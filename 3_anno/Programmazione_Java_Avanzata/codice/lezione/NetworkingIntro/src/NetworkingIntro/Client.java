package NetworkingIntro;

import java.io.Serializable;
import java.util.function.Consumer;

public class Client extends NetworkConnection{

    public Client(String ip, int port, Consumer<Serializable> receiveCallback) {
        super(ip, port, receiveCallback);
    }

    @Override
    public boolean isServer() {
        return false;
    }
}
