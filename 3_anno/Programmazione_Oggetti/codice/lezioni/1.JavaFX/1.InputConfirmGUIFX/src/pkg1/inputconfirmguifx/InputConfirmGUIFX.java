/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMain.java to edit this template
 */
package pkg1.inputconfirmguifx;

import javafx.application.Application;
import javafx.beans.binding.Bindings;
import javafx.beans.binding.BooleanBinding;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

/**
 *
 * @author emanueletocci
 */
public class InputConfirmGUIFX extends Application {
    
    @Override
    public void start(Stage primaryStage) {
        Label inputLbl = new Label();
        inputLbl.setText("Input");
        
        Label confirmLbl = new Label();
        confirmLbl.setText("Confirm Input");
        
        TextField inputTfd = new TextField();
        TextField confirmTfd = new TextField();

        Button btn = new Button();
        
        btn.setText("Ok");
        btn.setOnAction(new EventHandler<ActionEvent>() {
            
            @Override
            public void handle(ActionEvent event) {
                inputLbl.setText(inputTfd.getText());
                confirmLbl.setText(confirmTfd.getText());
                System.out.println("evento: " + event);            
            }
        });
        
        VBox root = new VBox();
        HBox row1 = new HBox();
        HBox row2 = new HBox();
        
        row1.getChildren().addAll(inputLbl, inputTfd);
        row2.getChildren().addAll(confirmLbl, confirmTfd);
        row1.setSpacing(10);
        row2.setSpacing(10);

        root.getChildren().addAll(row1, row2, btn);
        
        root.setAlignment(Pos.CENTER);
        Scene scene = new Scene(root, 600, 500);

        primaryStage.setTitle("Input Confirm GUI");
        primaryStage.setScene(scene);
        primaryStage.show();
        BooleanBinding check = Bindings.or(inputTfd.textProperty().isEmpty(), inputTfd.textProperty().isNotEqualTo(confirmTfd.textProperty()));
        btn.disableProperty().bind(check);
        btn.setOnAction(event -> buttonAction());
    }

    private void buttonAction(){
        System.out.println("Cliccato");
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}
