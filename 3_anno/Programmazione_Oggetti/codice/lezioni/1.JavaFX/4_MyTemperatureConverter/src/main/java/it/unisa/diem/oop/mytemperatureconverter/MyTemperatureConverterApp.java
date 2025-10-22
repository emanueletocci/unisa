/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.mytemperatureconverter;

/**
 *
 * @author leonardorundo
 */

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class MyTemperatureConverterApp extends Application {
    
    @Override
    public void start(Stage primaryStage) {
        MyTemperatureConverterView view = new MyTemperatureConverterView();
        new MyTemperatureConverterController(view);

        primaryStage.setTitle("My Temperature Converter");
        primaryStage.setScene(new Scene(view, 325, 325));
        primaryStage.centerOnScreen();
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
    
}
