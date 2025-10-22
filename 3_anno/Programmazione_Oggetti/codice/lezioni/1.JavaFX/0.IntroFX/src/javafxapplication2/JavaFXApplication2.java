/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMain.java to edit this template
 */
package javafxapplication2;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

/**
 *
 * @author emanueletocci
 */
public class JavaFXApplication2 extends Application {

    @Override
    public void start(Stage primaryStage) {
        Label lbl = new Label();
        lbl.setText("Label");

        TextField tfd = new TextField();

        Button btn = new Button();
        btn.setText("Click me!'");

        btn.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent event) {
                lbl.setText(tfd.getText());
                System.out.println("evento: " + event);
            }
        });

        VBox root = new VBox();
        root.getChildren().addAll(lbl, tfd, btn);
        root.setAlignment(Pos.CENTER);
        root.setPadding(new Insets(30));
        root.setSpacing(10);

        Scene scene = new Scene(root, 300, 250);

        primaryStage.setTitle("Hello World!");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }

}
