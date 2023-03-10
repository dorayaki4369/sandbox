package d13136.webapp.webapp;

import java.util.HashMap;
import java.util.Map;

import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

/**
 * 第6回で使うコントローラ
 */
@Controller
@RequestMapping("/lecture06")
public class Lecture06Controller {

    /**
     * 辞書情報を保存するフィールド
     */
    private Map<String, String> dictionary = new HashMap<>();

    /**
     * 辞書（登録）: get
     */
    @GetMapping("/dictionary/register")
    public static String dictionaryRegister() {
        return "lecture06/dictionaryRegister";
    }

    /**
     * 辞書（登録）: post
     */
    @PostMapping("/dictionary/register")
    public String dictionaryRegister(ModelMap modelMap, @RequestParam("english") String english, @RequestParam("japanese") String japanese) {
        dictionary.put(english, japanese);
        modelMap.addAttribute("message", "「" + english + "/" + japanese + "」を登録しました。");
        return "lecture06/dictionaryRegister";
    }

    /**
     * 辞書（検索）: get
     */
    @GetMapping("/dictionary/search")
    public static String dictionarySearch() {
        return "lecture06/dictionarySearch";
    }

    /**
     * 辞書（検索）: post
     */
    @PostMapping("/dictionary/search")
    public String dictionarySearch(ModelMap modelMap, @RequestParam("english") String english) {
        String japanese = dictionary.get(english);
        String result;
        if (japanese != null) {
            result = "「" + english + "」の検索結果は「" + japanese + "」です。";
        } else {
            result = "「" + english + "」は登録されていません。";
        }
        modelMap.addAttribute("result", result);
        return "lecture06/dictionarySearch";
    }

    /**
     * 辞書（一覧）
     */
    @GetMapping("/dictionary/list")
    public String dictionaryList(ModelMap modelMap) {
        modelMap.addAttribute("dictionary", dictionary);
        return "lecture06/dictionaryList";
    }

    /**
     * 辞書（削除）: get
     */
    @GetMapping("/dictionary/delete")
    public static String dictionaryDelete() {
        return "lecture06/dictionaryDelete";
    }

    /**
     * 辞書（削除）: post
     */
    @PostMapping("/dictionary/delete")
    public String dictionaryDelete(ModelMap modelMap, @RequestParam("english") String english) {
        String japanese = dictionary.get(english);
        String result;
        if (japanese != null) {
            dictionary.remove(english);
            result = "「" + english + "」「" + japanese + "」は削除されました。";
        } else {
            result = "「" + english + "」は登録されていません。";
        }
        modelMap.addAttribute("result", result);
        return "lecture06/dictionaryDelete";
    }
}
