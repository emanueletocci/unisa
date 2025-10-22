/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package it.unisa.diem.oop.mytemperatureconverter;

import javafx.beans.property.SimpleStringProperty;
import javafx.util.StringConverter;
import javax.script.Bindings;

/**
 *
 * @author leonardorundo
 */
public class MyTemperatureConverterController {
    
    private final MyTemperatureConverterView view;
    private final SimpleStringProperty celsiusString;
    private final SimpleStringProperty fahrString;

    public MyTemperatureConverterController(MyTemperatureConverterView view) {
        this.view = view;
        this.celsiusString = new SimpleStringProperty("");
        this.fahrString = new SimpleStringProperty("");
        bindCelsiusWithFahr();
        bindInvertToMode();
        bindInputToConversion();
        bindConversionToResult();
    }

    public void bindInvertToMode() {
        view.lblMode.textProperty()
                .bind(Bindings.when(view.chkInvert.selectedProperty())
                        .then("Fahr to Celsius")
                        .otherwise("Celsius to Fahr"));
    }

    public void bindCelsiusWithFahr() {
        Bindings.bindBidirectional(celsiusString, fahrString, new StringConverter<String>() {
            @Override
            public String toString(String object) {
                try {
                    return Float.toString((Float.valueOf(object) - 32) * 5 / 9);
                } catch (NumberFormatException ex) {
                    return "";
                }
            }

            @Override
            public String fromString(String string) {
                try {
                    return Float.toString(Float.valueOf(string) * 9 / 5 + 32);
                } catch (NumberFormatException ex) {
                    return "";
                }
            }
        });
    }

    public void bindInputToConversion() {
        celsiusString.bind(view.txtInput.textProperty());
        view.chkInvert.setOnAction(event -> {
            if (view.chkInvert.isSelected()) {
                celsiusString.unbind();
                fahrString.bind(view.txtInput.textProperty());
            } else {
                fahrString.unbind();
                celsiusString.bind(view.txtInput.textProperty());
            }
        });
    }

    public void bindConversionToResult() {
        view.lblResult.textProperty()
                .bind(Bindings.when(view.chkInvert.selectedProperty())
                        .then(celsiusString)
                        .otherwise(fahrString));
    }
    
}
