package myChatFX.network;

import javafx.concurrent.Service;
import javafx.concurrent.Task;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.function.Consumer;

public abstract class NetworkConnection {
    private final String ip;
    private final int port;
    private final Consumer<Serializable> receiveCallback;
    private final ConnectionService connection;

    public abstract boolean isServer();

    public NetworkConnection(String ip, int port, Consumer<Serializable> receiveCallback) {
        this.ip = ip;
        this.port = port;
        this.receiveCallback = receiveCallback;
        this.connection = new ConnectionService();
    }

    public void sendMessage(Serializable message) {
        connection.send(message);
    }

    public void connect() {
        connection.start();
    }

    public void disconnect() {
        connection.disconnect(); // Chiude correttamente
    }

    private class ConnectionService extends Service<Void> {
        private Socket socket;
        private ObjectOutputStream outputStream;

        @Override
        protected Task<Void> createTask() {
            return new Task<Void>() {
                @Override
                protected Void call() {
                    try (
                            Socket s = isServer() ? new ServerSocket(port).accept() : new Socket(ip, port);
                            ObjectOutputStream out = new ObjectOutputStream(s.getOutputStream());
                            ObjectInputStream in = new ObjectInputStream(s.getInputStream())
                    ) {
                        socket = s;
                        outputStream = out;

                        while (true) {
                            Serializable message = (Serializable) in.readObject();
                            receiveCallback.accept(message);
                        }
                    } catch (IOException e) {
                    } catch (ClassNotFoundException e) {
                        e.printStackTrace();
                    }
                    return null;
                }
            };
        }

        public void send(Serializable message) {
            try {
                if (outputStream != null) {
                    outputStream.writeObject(message);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        public void disconnect() {
            cancel();
        }
    }

}
