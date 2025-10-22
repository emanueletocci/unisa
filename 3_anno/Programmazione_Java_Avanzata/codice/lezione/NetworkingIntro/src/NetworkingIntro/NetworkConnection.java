package NetworkingIntro;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.function.Consumer;

public abstract class NetworkConnection {
    private String ip;
    private int port;
    private ConnectionThread connection;
    private Consumer<Serializable> receiveCallback;

    public abstract boolean isServer();

    public NetworkConnection(String ip, int port, Consumer<Serializable> receiveCallback) {
        this.ip = ip;
        this.port = port;
        this.receiveCallback = receiveCallback;
        this.connection = new ConnectionThread();
    }

    public void sendMessage(Serializable message) {
        try {
            connection.outputStream.writeObject(message);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // se non si utilizzasse consumer
    public void onReceive(Serializable message) {
        System.out.println("Received message: " + message);
    }

    public void connect(){
        connection.start();
    }

    public void disconnect(){
        try{
            connection.socket.close();
        } catch (IOException e){
            e.printStackTrace();
        }
    }

    private class ConnectionThread extends Thread{
        ObjectOutputStream outputStream;
        Socket socket;

        @Override
        public void run() {
            try (Socket socket = isServer() ? new ServerSocket(port).accept() : new Socket(ip, port);
                 // Bisogna definire prima l'outputStream!!
                 ObjectOutputStream outputStream = new ObjectOutputStream(socket.getOutputStream());
                 ObjectInputStream inputStream = new ObjectInputStream(socket.getInputStream());
            ){
                this.outputStream = outputStream;
                this.socket = socket;
                while(true){
                    Serializable message = (Serializable) inputStream.readObject();
                    receiveCallback.accept(message);
                    //onReceive(message); senza consumer
                }
            } catch(IOException e){
            } catch(ClassNotFoundException e){
                e.printStackTrace();
            }
        }
    }
}
