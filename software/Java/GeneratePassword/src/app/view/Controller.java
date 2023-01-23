package app.view;

import java.io.UnsupportedEncodingException;
import java.net.URL;
import java.util.Random;
import java.util.ResourceBundle;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

public class Controller implements Initializable {
	private static Random random = new Random();
	@FXML
	private Label numPassLabel;
	@FXML
	private Label PassLabel;
	@FXML
	private Button regenarateButton;

	@Override
	public void initialize(URL location, ResourceBundle resources) {
		String numPass;
		String pass;

		numPass = genNumPasswoed();
		pass = genPassword();
		numPassLabel.setText(numPass);
		PassLabel.setText(pass);
	}

	@FXML
	private void genaratePasswordHandler() {
		initialize(null, null);
	}

	private static String genNumPasswoed() {
		String num = "";

		for (int i = 0; i < 10; i++) {
			num = num.concat(String.valueOf(random.nextInt(10)));
		}
		return num;
	}

	private static String genPassword() {
		int range = 0;
		int firstCode = 0;
		byte[] asciiCode = new byte[10];

		for (int i = 0; i < asciiCode.length; i++) {
			switch (random.nextInt(3)) {
				case 0:
					//大文字アルファベット
					firstCode = 65;
					range = 26;
					break;

				case 1:
					//小文字アルファベット
					firstCode = 97;
					range = 26;
					break;

				case 2:
					//数字
					firstCode = 48;
					range = 10;
					break;

				default:
					break;
			}
			asciiCode[i] = (byte) (firstCode + random.nextInt(range));
		}
		String pass;
		try {
			pass = new String(asciiCode, "US-ASCII");
			return pass;
		}
		catch (UnsupportedEncodingException e) {
			e.printStackTrace();
			return null;
		}
	}
}
