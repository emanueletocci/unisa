/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMain.java to edit this template
 */
package myspeedconverter;

import javafx.application.Application;
import javafx.beans.binding.Bindings;
import javafx.beans.binding.NumberBinding;
import javafx.beans.property.DoubleProperty;
import javafx.beans.property.SimpleDoubleProperty;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;
import javafx.util.StringConverter;
import javafx.util.converter.DoubleStringConverter;

/**
 *
 * @author emanueletocci
 */
public class MySpeedConverter extends Application {
    
    @Override
    public void start(Stage primaryStage) {
        
        //interfaccia
        TextField tfd = new TextField();
        tfd.setPrefColumnCount(5);  //limita la larghezza del text field
        Label display = new Label();
        Label symbol = new Label();
        symbol.setText("km/h --> kts");
        
        HBox root = new HBox(30);
        root.getChildren().addAll(tfd, symbol, display);
        root.setAlignment(Pos.CENTER);
        root.setPadding(new Insets(30));
        Scene scene = new Scene(root, 300, 250);
        root.setStyle("-fx-font: 16 Sans;");
        
        // comportamenti
        
        DoubleProperty input = new SimpleDoubleProperty();
        StringConverter sc = new DoubleStringConverter();
        Bindings.bindBidirectional(tfd.textProperty(), input, sc);
        NumberBinding result = input.divide(1.852);
        display.textProperty().bind(result.asString("%.2f"));
        
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
