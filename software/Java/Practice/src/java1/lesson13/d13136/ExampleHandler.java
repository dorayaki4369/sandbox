package lesson13.d13136;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;

public class ExampleHandler implements EventHandler<ActionEvent> {
    @Override
    public void handle(ActionEvent event) {
        System.out.println("イベント発生");
    }
}
