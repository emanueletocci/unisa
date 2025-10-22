/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package myspeedconverter;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;

/**
 *
 * @author emanueletocci
 */
public class MySpeedConverterView extends HBox{
    public TextField input;
    public Label display;
    
    public MySpeedConverterView(){
        super();
        initComponents();
    }
    
    public void initComponents(){
        //interfaccia
        input = new TextField();
        input.setPrefColumnCount(5);  //limita la larghezza del text field
        display = new Label();
        Label symbol = new Label();
        symbol.setText("km/h --> kts");
        
        this.getChildren().addAll(input, display);
        this.setAlignment(Pos.CENTER);
        this.setPadding(new Insets(30));
        this.setSpacing(20);
        this.setStyle("-fx-font: 16 Sans;");
    }
}
