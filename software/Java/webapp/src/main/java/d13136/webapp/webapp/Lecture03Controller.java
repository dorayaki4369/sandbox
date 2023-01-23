package d13136.webapp.webapp;

import java.time.LocalTime;

import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestMapping;

/**
 * 第3回で使うコントローラ
 */
@Controller
@RequestMapping("/lecture03")
public class Lecture03Controller {

    @RequestMapping("/hello")
    public static String hello() {
        return "lecture03/hello"; // テンプレートのファイル名を返す
    }

    @RequestMapping("/dice")
    public static String dice(ModelMap modelMap) {
        int pips = (int) Math.floor(Math.random() * 6) + 1;
        modelMap.addAttribute("pips", pips);
        return "lecture03/dice";
    }

    @RequestMapping("/greeting")
    public static String greeting(ModelMap modelMap) {
        LocalTime localTime = LocalTime.now();
        int hour = localTime.getHour();
        String message;
        if (4 <= hour && hour < 11) {
            message = "おはよう";
        } else if (11 <= hour && hour < 16) {
            message = "こんにちは";
        } else {
            message = "こんばんは";
        }
        modelMap.addAttribute("message", message);
        return "lecture03/greeting";
    }

}
