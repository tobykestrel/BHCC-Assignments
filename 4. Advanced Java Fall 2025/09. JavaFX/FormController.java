/*=======================================
| Toby Hansen, November 10 2025.        |
| Java FX Assignment, CSC-285-201.      |
| This program collects passenger info. |
=======================================*/

package application;

import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.stage.Stage;
import java.io.FileWriter;
import java.io.IOException;
import java.time.format.DateTimeFormatter;

public class FormController {

    @FXML private TextField nameField;
    @FXML private TextField ageField;
    @FXML private ComboBox<String> sexBox;
    @FXML private ComboBox<String> fromBox;
    @FXML private ComboBox<String> toBox;
    @FXML private DatePicker departurePicker;
    @FXML private TextField priceField;

    private String CSV_FILE = "src/application/output.csv"; // The path of the output csv file.

    @FXML
    private void initialize() {
    	// This section initializes the combo box options.
        sexBox.getItems().addAll("Male", "Female");
        fromBox.getItems().addAll("Boston", "New York City", "Tokyo", "London", "Reykjavik");
        toBox.getItems().addAll("Boston", "New York City", "Tokyo", "London", "Reykjavik");
    }

    @FXML
    private void handleSave() {
        try {
        	// This section gets all the field values.
            String name = nameField.getText();
            int age = Integer.parseInt(ageField.getText());
            String sex = sexBox.getValue();
            String fromCity = fromBox.getValue();
            String toCity = toBox.getValue();
            String date = departurePicker.getValue().format(DateTimeFormatter.ISO_DATE);
            double price = Double.parseDouble(priceField.getText());

            // This section makes sure that all the values are filled in.
            if (name.isEmpty() || sex == null || fromCity == null || toCity == null || date.isEmpty()) {
                showAlert("Error", "Please fill all fields correctly.");
                return;
            }

            // This section attempts to write the passenger information to the output csv file.
            try (FileWriter writer = new FileWriter(CSV_FILE, true)) {
                writer.append(String.format("%s,%d,%s,%s,%s,%s,%.2f%n", name, age, sex, fromCity, toCity, date, price));
            }
            
            // If everything worked as expected, the user is notified and the values are cleared.
            showAlert("Success", "Passenger data saved successfully!");
            handleClear();

        } catch (NumberFormatException e) { showAlert("Error", "Please give valid input for Age and Ticket Price.");
        } catch (IOException e) { showAlert("Error", "Could not write to file: " + e.getMessage()); }
    }

    @FXML
    private void handleClear() {
    	// This section clears any filled in values and resets the fields.
        nameField.clear();
        ageField.clear();
        sexBox.getSelectionModel().clearSelection();
        fromBox.getSelectionModel().clearSelection();
        toBox.getSelectionModel().clearSelection();
        departurePicker.setValue(null);
        priceField.clear();
    }

    @FXML
    private void handleClose() {
    	// This section closes the program.
        Stage stage = (Stage)nameField.getScene().getWindow();
        stage.close();
    }

    // This function takes two string inputs, a title and message, and displays them in an alert pop-up.
    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
}
