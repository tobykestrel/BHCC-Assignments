/*================================
| Toby Hansen, November 22 2025. |
| Java FX Test 3, CSC-285-201.   |
| This program is a text editor. |
================================*/

package application;

import javafx.fxml.FXML;
import javafx.stage.Stage;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.stage.FileChooser;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class FormController {

    @FXML private TextField filePathField;
    @FXML private TextArea textArea;
    @FXML private Button selectFileButton;
    @FXML private Button saveButton;

    private File selectedFile;

    @FXML
    private void initialize() {
    	// This makes sure that the text doesn't go off the screen.
        textArea.setWrapText(true);
    }
    
    @FXML
    private void selectFile() {
    	// This section handles the file selecting and writes the text from the doc into the text field for editing.
        FileChooser chooser = new FileChooser();
        chooser.getExtensionFilters().add(new FileChooser.ExtensionFilter("Text Files", "*.txt"));
        File file = chooser.showOpenDialog(null);

        if (file != null) {
            try {
                selectedFile = file;
                filePathField.setText(file.getAbsolutePath());
                textArea.setText(Files.readString(Paths.get(file.getAbsolutePath())));
            } catch (IOException e) { showAlert("Error reading file", e.getMessage()); }
        }
    }

    @FXML
    private void saveFile() {
    	// This section handles the file saving, and updates the user on the status of the save.
        if (selectedFile == null) {
            showAlert("No File Selected", "Please select a file before saving.");
            return;
        }
        try {
            Files.writeString(Paths.get(selectedFile.getAbsolutePath()), textArea.getText());
            showAlert("Success", "File saved successfully!");
        } catch (IOException e) { showAlert("Error saving file", e.getMessage()); }
    }

    private void showAlert(String title, String message) {
    	// This section shows a pop up alert for errors or information.
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }

    @FXML
    private void handleClose() {
    	// This section closes the program.
        Stage stage = (Stage)filePathField.getScene().getWindow();
        stage.close();
    }
}
