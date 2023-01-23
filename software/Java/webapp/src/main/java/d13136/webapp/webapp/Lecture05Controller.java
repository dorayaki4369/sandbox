package d13136.webapp.webapp;

import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

/**
 * 第5回で使うコントローラ
 */
@Controller
@RequestMapping("/lecture05")
public class Lecture05Controller {

    /**
     * 掲示板: コメントを保存しておくフィールド
     */
    private List<BbsComment> commentList = new ArrayList<>();

    /**
     * 掲示板: get
     */
    @GetMapping("/bbs")
    public String bbsGet(ModelMap modelMap) {
        modelMap.addAttribute("commentList", commentList);
        return "lecture05/bbs";
    }

    /**
     * 掲示板: post
     */
    @PostMapping("/bbs")
    public String bbsGet(ModelMap modelMap, @RequestParam("body") String body, @RequestParam("name") String name) {
        BbsComment comment = new BbsComment();
        comment.body = body;
        comment.name = name;
        comment.date = new Date();
        commentList.add(comment);
        modelMap.addAttribute("commentList", commentList);
        return "lecture05/bbs";
    }


    /**
     * 辞書情報を保存するフィールド
     */
    private Map<String, String> dictionary = new HashMap<>();

    /**
     * 辞書（登録）: get
     */
    @GetMapping("/dictionary/register")
    public static String dictionaryRegister() {
        return "lecture05/dictionaryRegister";
    }

    /**
     * 辞書（登録）: post
     */
    @PostMapping("/dictionary/register")
    public String dictionaryRegister(ModelMap modelMap, @RequestParam("english") String english, @RequestParam("japanese") String japanese) {
        dictionary.put(english, japanese);
        modelMap.addAttribute("message", "「" + english + "/" + japanese + "」を登録しました。");
        return "lecture05/dictionaryRegister";
    }

    /**
     * 辞書（検索）: get
     */
    @GetMapping("/dictionary/search")
    public static String dictionarySearch() {
        return "lecture05/dictionarySearch";
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
        return "lecture05/dictionarySearch";
    }

    /**
     * 辞書（一覧）
     */
    @GetMapping("/dictionary/list")
    public String dictionaryList(ModelMap modelMap) {
        modelMap.addAttribute("dictionary", dictionary);
        return "lecture05/dictionaryList";
    }
}
