/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXML2.java to edit this template
 */
package pkg3_mystudentlist;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;

/**
 *
 * @author emanueletocci
 */
public class MyStudentListViewController implements Initializable {
    
    private Label label;
    @FXML
    private TextField nameField;
    @FXML
    private TextField surnameField;
    @FXML
    private TextField codeField;
    @FXML
    private Button addButton;
    @FXML
    private Button delButton;
    @FXML
    private TableView<Student> studentsTable;
    @FXML
    private TableColumn<Student, String> nameClm;
    @FXML
    private TableColumn<Student, String> surnameClm;
    @FXML
    private TableColumn<Student, String> codeClm;
    
    private ObservableList<Student> students;

    
//    private void handleButtonAction(ActionEvent event) {
//        System.out.println("You clicked me!");
//        label.setText("Hello World!");
//    }
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        students = FXCollections.observableArrayList();
        studentsTable.setItems(students);
        
        nameClm.setCellValueFactory(s -> {return new SimpleStringProperty(s.getValue().getName());});
        surnameClm.setCellValueFactory(new PropertyValueFactory("surname"));    //metodo alternativo compatto
        codeClm.setCellValueFactory(new PropertyValueFactory("code"));    

    }

    @FXML
    private void addStudent(ActionEvent event) {
        students.add(new Student(nameField.getText(), surnameField.getText(), codeField.getText()));
        
    }

    @FXML
    private void delStudent(ActionEvent event) {
    }
    
}
