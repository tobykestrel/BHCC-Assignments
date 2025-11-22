/*================================
| Toby Hansen, November 22 2025. |
| Java FX Test 3, CSC-285-201.   |
| This program is a text editor. |
================================*/

package application;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.Parent;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) {
        try {
            Parent root = FXMLLoader.load(getClass().getResource("Form.fxml"));
            primaryStage.setTitle("Welcome to File Editor");
            primaryStage.setScene(new Scene(root));
            primaryStage.show();
        } catch(Exception e) { e.printStackTrace(); }
    }

    public static void main(String[] args) { Application.launch(args); }
}
