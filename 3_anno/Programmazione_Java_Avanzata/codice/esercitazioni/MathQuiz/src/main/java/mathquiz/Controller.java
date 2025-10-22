package mathquiz;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import javafx.util.Duration;
import javafx.application.Platform;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import java.net.URL;
import java.util.ResourceBundle;

public class Controller implements Initializable {
    @FXML
    private TableColumn<NumericQuestionAttempt, String> attemptColumn;

    @FXML
    private TableColumn<NumericQuestionAttempt, String> outcomeColumn;

    @FXML
    private Button DoneButton;

    @FXML
    private Label FormLabel;

    @FXML
    private TextField answerField;

    @FXML
    private Label attemptLabel;

    @FXML
    private Button exportButton;

    @FXML
    private VBox formBox;

    @FXML
    private VBox gameBox;

    @FXML
    private TextField nameField;

    @FXML
    private Label questionLabel;

    @FXML
    private TextField questionNumberField;

    @FXML
    private VBox resultBox;

    @FXML
    private TableView<NumericQuestionAttempt> resultTable;

    @FXML
    private StackPane stackPane;

    @FXML
    private Button startButton;

    @FXML
    private TextField surnameField;

    @FXML
    private Label messageLabel;

    @FXML
    private Label timelineLabel;

    private int questionNumber;
    private int counter = 0;
    private NumericQuestion currentQuestion;
    private ObservableList<NumericQuestionAttempt> attemptList = FXCollections.observableArrayList();
    private int timeRemaining;
    private Timeline timer;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        startButton.setDisable(true);

        nameField.textProperty().addListener((observable, oldValue, newValue) -> checkFields());
        surnameField.textProperty().addListener((observable, oldValue, newValue) -> checkFields());
        questionNumberField.textProperty().addListener(observable -> checkFields());

        attemptColumn.setCellValueFactory(s -> new SimpleStringProperty(s.getValue().toString()));
        outcomeColumn.setCellValueFactory(s -> new SimpleStringProperty(s.getValue().getString()));

        resultTable.setItems(attemptList);
    }

    // Method to check the validity of the input fields
    private void checkFields() {
        String name = nameField.getText().trim();
        String surname = surnameField.getText().trim();
        String questionNumber = questionNumberField.getText().trim();

        boolean isValidName = !name.isEmpty() && name.matches("[a-zA-Z]+");
        boolean isValidSurname = !surname.isEmpty() && surname.matches("[a-zA-Z]+");
        boolean isValidQuestionNumber = !questionNumber.isEmpty() && questionNumber.matches("[1-9]");

        if (!isValidName && !name.isEmpty()) {
            mostraDialog(Alert.AlertType.ERROR, "Name Error", "You must insert only letters!");
            nameField.clear();
        }

        if (!isValidSurname && !surname.isEmpty()) {
            mostraDialog(Alert.AlertType.ERROR, "Surname Error", "You must insert only letters!");
            surnameField.clear();
        }

        if (!isValidQuestionNumber && !questionNumber.isEmpty()) {
            mostraDialog(Alert.AlertType.ERROR, "Question Number Error", "You must insert a number between 1 and 9!");
            questionNumberField.clear();
        }

        boolean allValid = isValidName && isValidSurname && isValidQuestionNumber;
        startButton.setDisable(!allValid);
    }

    // Method to handle the "Start" button click
    @FXML
    private void handleStart() {
        formBox.setVisible(false);
        gameBox.setVisible(true);
        questionNumber = Integer.parseInt(questionNumberField.getText());
        game();
    }

    // Method to handle the "Done" button click
    @FXML
    private void handleDone() {
        if (!answerField.getText().matches("-?\\d+")) {
            mostraDialog(Alert.AlertType.ERROR, "Error", "Insert a valid integer (positive or negative)!");
            return;
        }

        int givenAnswer = Integer.parseInt(answerField.getText());

        NumericQuestionAttempt attempt = new NumericQuestionAttempt(currentQuestion, givenAnswer);

        attemptList.add(attempt);

        if (questionNumber == counter) {
            gameBox.setVisible(false);
            resultBox.setVisible(true);
            messageLabel.setText("Dear " + nameField.getText() + " " + surnameField.getText() + ", thank you to complete the game! Export your results.");
            mostraDialog(Alert.AlertType.INFORMATION, "End Game", "You have completed the game! See the results.");
        } else {
            game();
        }
    }

    // Method to handle the export of results
    @FXML
    public void handleExport() {
        if (!attemptList.isEmpty()) {
            FileChooser fileChooser = new FileChooser();
            fileChooser.getExtensionFilters().add(new FileChooser.ExtensionFilter("txt", "*.txt"));
            fileChooser.setTitle("Export Results");

            File file = fileChooser.showSaveDialog(new Stage());

            if (file != null) {
                StringBuilder sb = new StringBuilder();
                try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
                    sb.append("ATTEMPT;USER RESULT;RIGHT/WRONG\n");
                    for (NumericQuestionAttempt attempt : attemptList) {
                        sb.append(attempt.toString())
                                .append(";")
                                .append(attempt.getQuestion().getResult())
                                .append(";")
                                .append(attempt.getString())
                                .append("\n");
                    }
                    writer.write(sb.toString());
                    mostraDialog(Alert.AlertType.INFORMATION,
                            "Export results",
                            "Results correctly exported \noutput: " + file.getAbsolutePath() + ".txt");

                } catch (IOException e) {
                    mostraDialog(Alert.AlertType.ERROR, "Error", "An error occurred while exporting the results.");
                    e.printStackTrace();
                }
            }
        } else {
            mostraDialog(Alert.AlertType.ERROR, "Error!", "No results found!");
        }
    }

    // Method that implements the game logic
    private void game() {
        timer();
        counter++;
        answerField.clear();
        answerField.clear();
        attemptLabel.setText(counter + "/" + questionNumber);
        currentQuestion = new NumericQuestion();
        questionLabel.setText(currentQuestion.toString());
    }

    // Method to handle the timer
    private void timer() {
        if (timer != null && timer.getStatus() == Timeline.Status.RUNNING) {
            timer.stop();
        }

        timeRemaining = 5;

        timer = new Timeline(new KeyFrame(Duration.seconds(1), event -> {
            timeRemaining--;
            timelineLabel.setText("Time remaining: " + timeRemaining + " seconds");

            if (timeRemaining <= 0) {
                timer.stop();
                timelineLabel.setText("Time's up!");

                Platform.runLater(() -> {
                    mostraDialog(Alert.AlertType.INFORMATION, "Time's up!", "Your time has expired. The game is over. See the results.");
                    gameBox.setVisible(false);
                    resultBox.setVisible(true);
                });
            }
        }));

        timer.setCycleCount(Timeline.INDEFINITE);
        timer.play();
    }

    // Method to show a dialog with a specific type, title, and message
    public void mostraDialog(Alert.AlertType type, String titolo, String messaggio) {
        Alert alert = new Alert(type);
        alert.setTitle(titolo);
        alert.setContentText(messaggio);
        alert.showAndWait();
    }

}
