package app;

import java.io.IOException;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

	@Override
	public void start(Stage primaryStage) throws Exception {
		primaryStage.setTitle("パスワード生成ツール");
		initView(primaryStage);
		primaryStage.show();
	}

	public static void initView(Stage stage) {
		try {
			FXMLLoader loader = new FXMLLoader();
			loader.setLocation(Main.class.getResource("view/PrimaryView.fxml"));
			Scene scene = new Scene(loader.load());
			stage.setScene(scene);
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		Application.launch(Main.class);
	}
}
