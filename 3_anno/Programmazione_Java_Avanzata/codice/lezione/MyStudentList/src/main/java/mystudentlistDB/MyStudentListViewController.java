/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mystudentlistDB;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;

import javafx.application.Platform;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.collections.transformation.FilteredList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.control.cell.TextFieldTableCell;
import javafx.stage.FileChooser;
import mystudentlistDB.dao.StudentDAO;
import mystudentlistDB.dao.StudentDAOPostgres;


/**
 * @author lucagreco
 */
public class MyStudentListViewController implements Initializable {

    @FXML
    private MenuItem saveButton;
    @FXML
    private TextField nameField;
    @FXML
    private TextField surnameField;
    @FXML
    private TextField codeField;
    @FXML
    private Button removeButton;
    @FXML
    private TableView<Studente> studentTable;
    @FXML
    private TableColumn<Studente, String> nameClm;
    @FXML
    private TableColumn<Studente, String> surnameClm;
    @FXML
    private TableColumn<Studente, String> codeClm;

    @FXML
    private TextField searchField;

    private ObservableList<Studente> studenti;
    private FilteredList<Studente> filteredStudenti;
    private StudentDAO studentDAO;

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        nameClm.setCellValueFactory(new PropertyValueFactory("nome"));
        surnameClm.setCellValueFactory(new PropertyValueFactory("cognome"));
        codeClm.setCellValueFactory(new PropertyValueFactory("matricola"));
        nameClm.setCellFactory(TextFieldTableCell.forTableColumn());
        surnameClm.setCellFactory(TextFieldTableCell.forTableColumn());
        codeClm.setCellFactory(TextFieldTableCell.forTableColumn());

        studentTable.getSelectionModel().setCellSelectionEnabled(true);

        studenti = FXCollections.observableArrayList();
        studentTable.setItems(studenti);

        studentDAO = new StudentDAOPostgres();
        try {
            studenti.addAll(studentDAO.elencaTutti());
        } catch (Exception ex) {
            ex.printStackTrace();
        }

        initItems();

        TextFormatter<String> formatter = new TextFormatter<>(change -> {
            if (change.getControlNewText().matches("\\d*")) {
                return change;
            }
            return null;
        });

        codeField.setTextFormatter(formatter);

        searchField.textProperty().addListener((observable, oldValue, newValue) -> {
            if (newValue.isEmpty()) {
                studentTable.setItems(studenti);    // mostra la collezione originale
            } else {
                search();  // mostra la collezione filtrata
            }
        });

        codeClm.setOnEditCommit(event -> {
            Studente studente = (Studente) event.getRowValue();

            if (event.getNewValue().matches("\\d+")) {
                studente.setMatricola(event.getNewValue());
            } else {
                showDialog(Alert.AlertType.ERROR, "Errore", "La matricola deve contenere solo numeri!!");
                studentTable.refresh();
            }
        });

    }

    public void search() {
        filteredStudenti = new FilteredList<>(studenti, s -> {
            return String.join(" ", s.getNome(), s.getCognome(), s.getMatricola()).toLowerCase().contains(searchField.getText().toLowerCase())
                    || String.join(" ", s.getCognome(), s.getNome(), s.getMatricola()).toLowerCase().contains(searchField.getText().toLowerCase());
        });
        studentTable.setItems(filteredStudenti);    // mostra la collezione filtrata
    }

    private void initItems() {
        studenti.add(new Studente("Mario", "Rossi", "06127001"));
        studenti.add(new Studente("Ernesto", "Rossi", "06127002"));
        studenti.add(new Studente("Davide", "Rossi", "06127003"));
    }

    @FXML
    private void openFile(ActionEvent event) {
        FileChooser fc = new FileChooser();
    }

    @FXML
    private void saveFile(ActionEvent event) {

        FileChooser fc = new FileChooser();
        File file = fc.showSaveDialog(nameField.getParent().getScene().getWindow());
        if (file != null) {
            try (PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(file)))) {
                for (Studente s : studenti) {
                    pw.append(s.getNome() + ';');
                    pw.append(s.getCognome() + ';');
                    pw.append(s.getMatricola() + '\n');
                }
            } catch (IOException ex) {
                Logger.getLogger(MyStudentListViewController.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    @FXML
    private void quitApp(ActionEvent event) {
        Platform.exit();
    }

    @FXML
    private void addStudent(ActionEvent event) {
        studenti.add(new Studente(nameField.getText(), surnameField.getText(), codeField.getText()));

        try{
            studentDAO.inserisci(s);
            studenti.add(s);
        }
    }

    @FXML
    private void removeStudent(ActionEvent event) {
        Studente s = studentTable.getSelectionModel().getSelectedItem();
        studenti.remove(s);
    }

    @FXML
    private void updateName(TableColumn.CellEditEvent<Studente, String> event) {
        Studente s = studentTable.getSelectionModel().getSelectedItem();
        s.setNome(event.getNewValue());
    }

    // Method to show a dialog with a specific type, title, and message
    public void showDialog(Alert.AlertType type, String titolo, String messaggio) {
        Alert alert = new Alert(type);
        alert.setTitle(titolo);
        alert.setContentText(messaggio);
        alert.showAndWait();
    }
}
