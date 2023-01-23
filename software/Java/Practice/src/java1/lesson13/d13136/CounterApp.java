package lesson13.d13136;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class CounterApp extends Application implements EventHandler<ActionEvent>{
	private Label label;
	private Button countButton;
	private Button resetButton;
	private int count = 0;

	@Override
	public void start(Stage primaryStage) throws Exception {
		//ラベル
		this.label = new Label();
		this.label.setText("0");
		this.label.relocate(10, 10);

        // カウントボタン
        countButton = new Button();
        countButton.setText("カウント");
        countButton.relocate(10, 40);
        countButton.setOnAction(this);

        // リセットボタン
        resetButton = new Button();
        resetButton.setText("リセット");
        resetButton.relocate(10, 70);
        resetButton.setOnAction(this);

        // ペイン（レイアウト）
        Pane pane = new Pane();
        pane.getChildren().add(label); // ペインにラベルを追加
        pane.getChildren().add(countButton); // ペインにカウントボタンを追加
        pane.getChildren().add(resetButton); // ペインにリセットボタンを追加

        // シーン
        Scene scene = new Scene(pane, 150, 200);
        primaryStage.setScene(scene); // シーンにペインをセット

        // 最初はこれだけ
        primaryStage.setTitle("カウンター");
        primaryStage.show();
	}

    @Override
    public void handle(ActionEvent event) {
        Object source = event.getSource(); // イベントの発生源となっているインスタンスを取得する
        if (source.equals(countButton)) {
            count++;
        } else if (source.equals(resetButton)) {
            count = 0;
        }
        label.setText(Integer.toString(count));
    }
}
