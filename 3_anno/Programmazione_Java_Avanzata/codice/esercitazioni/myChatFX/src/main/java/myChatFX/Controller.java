package myChatFX;
import java.net.URL;
import java.util.List;
import java.util.ResourceBundle;

import javafx.application.Platform;
import javafx.scene.control.TextArea;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import myChatFX.network.Client;
import myChatFX.network.Server;
import myChatFX.utilities.PrintColors;

public class Controller implements Initializable {

    @FXML
    private TextField inputField;

    @FXML
    private Button yesButton;

    @FXML
    private Button noButton;

    @FXML
    private StackPane stackPane;

    @FXML
    private TextArea textArea;

    List<Node> paneChildren;
    Client client;
    Server server;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        paneChildren = stackPane.getChildren();

        inputField.setOnKeyPressed(e -> {
            if(e.getCode() == KeyCode.ENTER) {

                String sendMessage = inputField.getText();
                if(sendMessage.isEmpty()) return;

                if(server != null) {
                    server.sendMessage(sendMessage);
                    Platform.runLater(() -> textArea.appendText("Server: " + sendMessage + "\n"));

                } else {
                    client.sendMessage(sendMessage);
                    Platform.runLater(() -> textArea.appendText("Client: " + sendMessage + "\n"));
                }

                inputField.clear();
            }
        });
    }

    @FXML
    void startAsServer(ActionEvent event) throws InterruptedException {
        paneChildren.get(0).setVisible(false);
        paneChildren.get(1).setVisible(true);

        Stage stage = (Stage) paneChildren.get(0).getScene().getWindow();
        stage.setTitle("myChatFX - Server");

        server = new Server(12100, (message) ->
        {
            System.out.println("Server received: " + message);
            Platform.runLater(() -> textArea.appendText("Client: " + message + "\n"));
        });
        server.connect();

        System.out.println(PrintColors.format("Server started", PrintColors.GREEN));
        Thread.sleep(2000);
    }

    @FXML
    void startAsClient(ActionEvent event) throws InterruptedException {
        paneChildren.get(0).setVisible(false);
        paneChildren.get(1).setVisible(true);

        Stage stage = (Stage) paneChildren.get(0).getScene().getWindow();
        stage.setTitle("myChatFX - Client");

        client = new Client("127.0.0.1", 12100, message ->
        {
            System.out.println("Client received: " + message);
            Platform.runLater(() -> textArea.appendText("Server: " + message + "\n"));
        });
        client.connect();

        System.out.println(PrintColors.format("Client started", PrintColors.GREEN));
        Thread.sleep(2000);
    }

}
