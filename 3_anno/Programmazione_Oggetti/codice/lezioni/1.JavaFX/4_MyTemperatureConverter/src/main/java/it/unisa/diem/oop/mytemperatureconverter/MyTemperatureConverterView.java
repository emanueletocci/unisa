package it.unisa.diem.oop.mytemperatureconverter;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author leonardorundo
 */

import javafx.geometry.Pos;
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;

public class MyTemperatureConverterView extends VBox {
    public final Label lblMode;
    public final TextField txtInput;
    public final Label lblResult;
    public final CheckBox chkInvert;

    public MyTemperatureConverterView() {
        super();
        this.setSpacing(10);
        this.setAlignment(Pos.CENTER);

        this.lblMode = new Label();
        this.getChildren().add(lblMode);

        HBox hBoxInput = new HBox();
        hBoxInput.setSpacing(10);
        hBoxInput.setAlignment(Pos.CENTER);
        hBoxInput.getChildren().add(new Label("Input:"));
        this.txtInput = new TextField();
        hBoxInput.getChildren().add(txtInput);
        this.getChildren().add(hBoxInput);

        HBox hBoxResult = new HBox();
        hBoxResult.setSpacing(10);
        hBoxResult.setAlignment(Pos.CENTER);
        hBoxResult.getChildren().add(new Label("Result:"));
        this.lblResult = new Label();
        hBoxResult.getChildren().add(lblResult);
        this.getChildren().add(hBoxResult);

        this.chkInvert = new CheckBox("<--->");
        this.getChildren().add(chkInvert);
    }
    
}
