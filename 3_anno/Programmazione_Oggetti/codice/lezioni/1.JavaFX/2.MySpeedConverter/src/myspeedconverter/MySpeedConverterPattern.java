/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMain.java to edit this template
 */
package myspeedconverter;

import javafx.application.Application;
import static javafx.application.Application.launch;
import javafx.scene.Scene;
import javafx.stage.Stage;

/**
 *
 * @author emanueletocci
 */
public class MySpeedConverterPattern extends Application {
    
    @Override
    public void start(Stage primaryStage) {
        MySpeedConverterView view = new MySpeedConverterView();
        new MySpeedConverterController(view);
        Scene scene = new Scene(view, 450, 250);
        
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
