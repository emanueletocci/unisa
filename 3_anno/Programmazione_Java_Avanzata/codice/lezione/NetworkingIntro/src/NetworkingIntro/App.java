package NetworkingIntro;

public class App {
    public static void main(String[] args) throws InterruptedException {
        Server server = new Server(12100, message -> System.out.println("Server received: " + message));
        server.connect();

        System.out.println("Server started");
        Thread.sleep(2000);

        Client client = new Client("127.0.0.1", 12100, message -> System.out.println("Client received: " + message));
        client.connect();

        System.out.println("Client connected");
        Thread.sleep(1000);

        server.sendMessage("Hello Client");
        Thread.sleep(1000);

        client.sendMessage("Hello Server");
        Thread.sleep(1000);

        client.disconnect();
        server.disconnect();
    }
}
