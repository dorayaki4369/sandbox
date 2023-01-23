package nct.exam;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.regex.Pattern;

import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

/**
 * d13136下にある全ページのコントローラです。
 *
 * <h2>リンク</h2>
 * <a href="localhost:18080/d13136/seiseki/register">成績登録ページ</a><br>
 * <a href="localhost:18080/d13136/seiseki/list">成績一覧ページ</a><br>
 * <a href="localhost:18080/d13136/account/register">アカウント登録ページ</a><br>
 * <a href="localhost:18080/d13136/account/list">アカウント一覧ページ</a><br>
 * <a href="localhost:18080/d13136/account/searchURL">URL検索ページ</a>
 *
 * <h2>機能一覧</h2>
 * <ul>
 * <li>英語、国語、数学の成績と名前を保存します。</li>
 * <li>正しい入力が行われているかチェックします。</li>
 * <li>保存された成績を利用してデータを解析し、表示します。</li>
 * <li>URLでアカウントを検索できます。</li>
 * <li>登録されたデータはいつでも削除できます。</li>
 * <li>登録されたデータはJSONファイルで保存されます。</li>
 * </ul>
 *
 * <h2>テスト方法</h2>
 * <h3>成績登録ページ</h3>
 * <ol>
 * <li><a href="localhost:18080/d13136/seiseki/register">成績登録ページ</a>にアクセスする。</li>
 * <li>何も入力せずに「登録」ボタンを押すと
 * <ul>
 * <li>名前:unknown</li>
 * <li>英語:0点</li>
 * <li>国語:0点</li>
 * <li>数学:0点</li>
 * </ul>
 * として登録されること(登録されたことを示すメッセージが現れる)を確認する。</li>
 * <li>名前欄に既に登録された名前を登録すると、上書きされること(上書きされたことを示すメッセージが現れる)を確認する。
 * <li>成績入力欄(英語、国語、数学)に数字以外の文字を登録すると、0点として登録されることを確認する。</li>
 * <li>成績入力欄に整数以外の数字または1~100以外の数字を登録すると、0点として登録されることを確認する。</li>
 * <li>上記条件に当てはまらない場合、入力した通りに登録されることを確認する。</li>
 * <li>登録した際に「studentList.json」が更新されたことを確認する。</li>
 * <li>「一覧」を押すと、成績一覧ページに移動することを確認する。</li>
 * </ol>
 * <h3>成績一覧ページ</h3>
 * <ol>
 * <li><a href="localhost:18080/d13136/seiseki/list">成績一覧ページ</a>にアクセスする。</li>
 * <li>成績登録ページで登録されたデータが以下の表のように表示されていることを確認する。
 * <table summary="成績一覧の例">
 * <tr>
 * <th>名前</th>
 * <th>英語</th>
 * <th>国語</th>
 * <th>数学</th>
 * <th>合計</th>
 * <th>平均</th>
 * </tr>
 * <tr>
 * <th>unknown</th>
 * <th>0</th>
 * <th>0</th>
 * <th>0</th>
 * <th>0</th>
 * <th>0.0</th>
 * </tr>
 * </table>
 * </li>
 * <li>チェックボックスに何もチェックせずに削除しようとすると、変化がないことを確認する。</li>
 * <li>チェックボックスにチェックをつけて削除しようとすると、チェックした分だけ削除できたことを確認する。</li>
 * <li>登録した際に「accountList.json」が更新されたことを確認する。</li>
 * <li>ウェブアプリケーションを再起動した際に、表に登録されているデータが変わらないことを確認する。</li>
 * <li>「登録」を押すと、成績登録ページに移動することを確認する。</li>
 * </ol>
 * <h3>アカウント登録ページ</h3>
 * <ol>
 * <li><a href="localhost:18080/d13136/account/register">アカウント登録ページ</a>にアクセスする。</li>
 * <li>何も入力せずに「登録」ボタンを押すと、アカウント名、パスワード、URLが不正というメッセージが示されることを確認する。</li>
 * <li>アカウント名に既に登録されているアカウント名を入力して「登録」ボタンを押すと、既に登録されているというメッセージが示されることを確認する。</li>
 * <li>アカウント名に文字を入力し、パスワードに10字未満21字以上の文字、もしくは大文字小文字のアルファベットと数字を含まない文字を入力して「登録」ボタンを押すと、パスワードが不正というメッセージが示されることを確認する。</li>
 * <li>アカウント名に文字を入力し、パスワードに上記条件を満たさない(不正でない)文字を入力して「登録」ボタンを押すと、パスワードと確認用パスワードが一致しないというメッセージが示されることを確認する。</li>
 * <li>アカウント名に文字を入力し、パスワードと確認用パスワードに上記条件を満たさない(不正でない)文字を入力し、http/httpsから始まらないURLを入力して「登録」ボタンを押すと、URLが不正というメッセージが示されることを確認する。</li>
 * <li>上記条件を満たさない(不正でない)データを入力して「登録」ボタンを押すと、登録が完了したメッセージが示されることを確認する。</li>
 * <li>登録した際に「accountList.json」が更新されたことを確認する。</li>
 * <li>同一パスワードがあった場合、それを示すメッセージを表示されることを確認する。</li>
 * <li>「一覧」を押すと、アカウント一覧ページに、「URL検索」を押すと、URL検索ページに移動することを確認する。</li>
 * </ol>
 * <h3>アカウント一覧ページ</h3>
 * <ol>
 * <li><a href="localhost:18080/d13136/account/list">アカウント一覧ページ</a>にアクセスする。</li>
 * <li>アカウント登録ページで登録されたデータが以下の表のように表示されていることを確認する。
 * <table summary="アカウント一覧の例">
 * <tr>
 * <th>アカウント名</th>
 * <th>パスワード</th>
 * <th>URL</th>
 * </tr>
 * <tr>
 * <th>hogehoge</th>
 * <th>awS1</th>
 * <th>https://m.youtube.com/</th>
 * </tr>
 * </table>
 * </li>
 * <li>チェックボックスに何もチェックせずに削除しようとすると、変化がないことを確認する。</li>
 * <li>チェックボックスにチェックをつけて削除しようとすると、チェックした分だけ削除できたことを確認する。</li>
 * <li>登録した際に「accountList.json」が更新されたことを確認する。</li>
 * <li>ウェブアプリケーションを再起動した際に、表に登録されているデータが変わらないことを確認する。</li>
 * <li>「登録」を押すと、アカウント登録ページに、「URL検索」を押すと、URL検索ページに移動することを確認する。</li>
 * </ol>
 * <h3>URL検索ページ</h3>
 * <ol>
 * <li><a href="localhost:18080/d13136/account/searchURL">URL検索ページ</a>にアクセスする。</li>
 * <li>登録されていないURLを検索しようとすると、見つからないことを示すメッセージが表示されることを確認する。</li>
 * <li>登録されているURLを検索しようとすると、完全一致する全てのアカウント情報が表示されることを確認する。</li>
 * <li>登録されているURLを検索しようとし、チェックボックスにチェックすると、完全一致する全てのアカウント情報が削除されることを確認する。</li>
 * <li>「登録」を押すと、アカウント登録ページに、「一覧」を押すと、アカウント一覧ページに移動することを確認する。</li>
 * </ol>
 *
 * @author dorayaki4369
 */
@Controller
@RequestMapping("/d13136")
public class D13136Controller {
	/** 成績保持者(生徒)のデータを格納します。 */
	private Collection<D13136Student> students = new ArrayList<>();//TreeSetにしても並び替えて表示してくれない
	/** 赤点対象者のデータを格納します。 */
	private Collection<D13136Student> badStudents = new ArrayList<>();
	/** アカウントのデータを格納します。 */
	private Collection<D13136Account> accounts = new ArrayList<>();
	/** 成績保持者(生徒)のデータを保存するファイルのパスです。 */
	private static final String studentsFile = "src/main/resources/data/studentList.json";
	/** アカウントのデータを保存するファイルのパスです。 */
	private static final String accountsFile = "src/main/resources/data/accountList.json";
	/** 削除データのハッシュ値を保存します。 */
	private List<String> hashCodes;

	/**
	 * 成績、アカウントリストが保存されているJSONファイルを読み出し、コントローラを初期化します。
	 */
	public D13136Controller() {
		students = D13136JsonData.decodeData(studentsFile, D13136Student.class);
		accounts = D13136JsonData.decodeData(accountsFile, D13136Account.class);
	}

	/**
	 * 成績登録ページを表示します。
	 *
	 * @return 成績登録ページへのリンク
	 */
	@GetMapping("/seiseki/register")
	public static String seisekiRegister() {
		return "d13136/seiseki/register";
	}

	/**
	 *
	 * 成績を登録します。<br>
	 * このメソッドは「登録」ボタンを押したときに実行されます。<br>
	 * 各教科の成績は0~100の範囲内にある整数でのみ保存でき、範囲外の値はすべて0になります。<br>
	 * 既に同名の成績保持者(生徒)が登録されていた場合、成績データを上書きします。
	 *
	 * @param modelMap
	 * @param name 成績保持者(生徒)の名前
	 * @param english 英語の成績
	 * @param japanese 国語の成績
	 * @param math 数学の成績
	 * @return 成績登録ページへのリンク
	 */
	@PostMapping("/seiseki/register")
	public String seisekiRegister(
			ModelMap modelMap,
			@RequestParam("name") String name,
			@RequestParam("english") String english,
			@RequestParam("japanese") String japanese,
			@RequestParam("math") String math) {

		//仕様上nullは入らないので空文字チェックを行う
		String regex = "[^0-9]";
		if (Pattern.compile(regex).matcher(english).find() || english.length() == 0) {
			english = "0";
		}
		if (Pattern.compile(regex).matcher(japanese).find() || japanese.length() == 0) {
			japanese = "0";
		}
		if (Pattern.compile(regex).matcher(math).find() || math.length() == 0) {
			math = "0";
		}

		D13136Student student = new D13136Student(name, Integer.parseInt(english), Integer.parseInt(japanese), Integer.parseInt(math));
		Integer correctedEng = (Integer) student.getValue("english");
		Integer correctedJap = (Integer) student.getValue("japanese");
		Integer correctedMat = (Integer) student.getValue("math");

		if (students.isEmpty()) {
			students.add(student);
			modelMap.addAttribute("message", student.getValue("name") + "の成績(英語:" + correctedEng + "点,国語:" + correctedJap + "点,数学:" + correctedMat + "点)を登録しました。");
		}
		else if (!students.contains(student)) {
			students.add(student);
			modelMap.addAttribute("message", student.getValue("name") + "の成績(英語:" + correctedEng + "点,国語:" + correctedJap + "点,数学:" + correctedMat + "点)を登録しました。");
		}
		else {
			students.remove(student);
			students.add(student);
			modelMap.addAttribute("message", student.getValue("name") + "の成績を上書き(英語:" + correctedEng + "点,国語:" + correctedJap + "点,数学:" + correctedMat + "点)しました。");
		}

		D13136JsonData.writeData(students, studentsFile);

		return "d13136/seiseki/register";
	}

	/**
	 * 成績リストページを表示します。
	 *
	 * @param modelMap
	 * @return 成績リストページへのリンク
	 */
	@GetMapping("/seiseki/list")
	public String seisekiList(ModelMap modelMap) {
		updateAvgData();
		updateBadStudents();
		modelMap.addAttribute("students", students);
		modelMap.addAttribute("badStudents", badStudents);
		modelMap.addAttribute("checks", this);
		modelMap.addAttribute("message", "名前横のチェックボックスで選択したデータを削除します。");
		return "d13136/seiseki/list";
	}

	/**
	 * 成績リストから任意の成績保持者(生徒)を複数削除します。<br>
	 * このメソッドは「削除」ボタンを押したときに実行されます。<br>
	 *
	 * @param modelMap
	 * @param holder 消去するデータのハッシュ値を取り出します。
	 * @return 成績リストページへのリンク
	 */
	@PostMapping("/seiseki/list")
	public String seisekiList(ModelMap modelMap, @ModelAttribute("checks") D13136Controller holder) {
		String message = "";

		for (String rmHashCode : holder.getHashCodes()) {
			for (D13136Student student : students) {
				if (student.hashCode() == Integer.parseInt(rmHashCode)) {
					students.remove(student);
					message = message.concat(student.getValue("name") + ",");
					break;
				}
			}
		}
		if (!message.equals("")) {
			message = message.substring(0, message.length() - 1);
			modelMap.addAttribute("message", message + "は消されました。");
			D13136JsonData.writeData(students, studentsFile);
		}
		else {
			modelMap.addAttribute("message", "名前横のチェックボックスで選択したデータを削除します。");
		}

		updateAvgData();
		updateBadStudents();

		modelMap.addAttribute("students", students);
		modelMap.addAttribute("badStudents", badStudents);

		return "d13136/seiseki/list";
	}

	/**
	 * 生徒データの各教科の平均情報を更新します。
	 */
	public void updateAvgData() {
		Integer avgEnglish = 0;
		Integer avgJapanese = 0;
		Integer avgMath = 0;

		for (D13136Student student2 : students) {
			if (student2.getValue("name").equals("平均")) {
				students.remove(student2);
				break;
			}
		}

		for (D13136Student student2 : students) {
			avgEnglish += (Integer) student2.getValue("english");
			avgJapanese += (Integer) student2.getValue("japanese");
			avgMath += (Integer) student2.getValue("math");
		}
		avgEnglish = avgEnglish / students.size();
		avgJapanese = avgJapanese / students.size();
		avgMath = avgMath / students.size();
		students.add(new D13136Student("平均", avgEnglish, avgJapanese, avgMath));
	}

	/**
	 * 赤点対象者リストを更新します。
	 */
	public void updateBadStudents() {
		badStudents.clear();
		for (D13136Student student : students) {
			boolean isBad = false;

			if ((Integer) student.getValue("english") < 60) {
				isBad = true;
			}
			else if ((Integer) student.getValue("japanese") < 60) {
				isBad = true;
			}
			else if ((Integer) student.getValue("english") < 60) {
				isBad = true;
			}

			if (isBad && !student.getValue("name").equals("平均")) {
				badStudents.add(student);
			}
		}
	}

	/**
	 * アカウント登録ページを表示します。
	 *
	 * @param modelMap
	 * @return アカウント登録ページのリンク
	 */
	@GetMapping("account/register")
	public static String accountRegister(ModelMap modelMap) {
		modelMap.addAttribute("message", "パスワードは大文字、小文字のアルファベットと数字を組み合わせた4字以上20字以下の文字列を入力してください。");
		return "d13136/account/register";
	}

	/**
	 * アカウント登録をします。<br>
	 * アカウント名とパスワード、URLの不正をチェックします。<br>
	 * <h3>不正になる条件:</h3>
	 * <ul>
	 * <li>アカウント名が空文字</li>
	 * <li>アカウント名の重複</li>
	 * </ul>
	 * <ul>
	 * <li>パスワードに大文字、小文字のアルファベットと数字が最低一つずつ含まれていない。</li>
	 * <li>パスワードが10字以上20字以下でない。</li>
	 * <li>パスワードと確認用パスワードが一致しない。</li>
	 * </ul>
	 * <ul>
	 * <li>URLがhttpもしくはhttpsから始まらない。</li>
	 * </ul>
	 *
	 * @param modelMap
	 * @param accountName アカウント名
	 * @param password パスワード
	 * @param password2nd パスワード(確認用)
	 * @param url URL
	 * @return アカウント登録ページのリンク
	 * @see #checkPassword(String)
	 */
	@PostMapping("account/register")
	public String accountRegister(
			ModelMap modelMap,
			@RequestParam("accountName") String accountName,
			@RequestParam("password") String password,
			@RequestParam("password2nd") String password2nd,
			@RequestParam("url") String url) {

		String errMessage = "アカウント登録に失敗しました。<br>";
		int errlength = errMessage.length();
		if (!accounts.isEmpty()) {
			if (accounts.contains(new D13136Account(accountName, password, url))) {
				errMessage = errMessage.concat("このアカウント名(" + accountName + ")は既に使用されています。<br>");
			}
		}
		if (accountName.length() == 0) {
			errMessage = errMessage.concat("空文字をアカウント名に登録することはできません。<br>");
		}
		if (checkPassword(password)) {
			errMessage = errMessage.concat("パスワードが不正です。<br>");
		}
		if (!password.equals(password2nd)) {
			errMessage = errMessage.concat("パスワードと確認用パスワードが一致しません。<br>");
		}
		if (!Pattern.compile("(http://|https://){1}[\\w\\.\\-/:\\#\\?\\=\\&\\;\\%\\~\\+]+").matcher(url).find()) {
			errMessage = errMessage.concat("URLが不正です。<br>");
		}

		//エラーが出なかったら実行
		if (errMessage.length() <= errlength) {
			accounts.add(new D13136Account(accountName, password, url));
			errMessage = "アカウント登録が完了しました。<br>";
			D13136JsonData.writeData(accounts, accountsFile);
		}
		//同一パスワードチェック
		//この処理はアカウント登録に成功してもしなくても実行するためここに置いた
		for (D13136Account account : accounts) {
			if (account.getValue("password").equals(password) && !account.getValue("name").equals(accountName)) {
				errMessage = errMessage.concat("[INFO]同一パスワードを持つアカウントが既に登録されています。<br>");
				break;
			}
		}

		modelMap.addAttribute("message", "パスワードは大文字、小文字のアルファベットと数字を組み合わせた4字以上20字以下の文字列を入力してください。");
		modelMap.addAttribute("errMessage", errMessage);

		return "d13136/account/register";
	}

	/**
	 * パスワードが不正でないかチェックします。<br>
	 * <br>
	 * <h3>不正になる条件:</h3>
	 * <ul>
	 * <li>10字未満、21字以上の長さ</li>
	 * <li>大文字、小文字のアルファベットと数字を含まない</li>
	 * </ul>
	 *
	 * @param password パスワード
	 * @return パスワードが正しい場合、Trueを返します。
	 */
	private static boolean checkPassword(String password) {
		//パスワード長さチェック
		if (password.length() < 10 && password.length() >= 21) {
			return false;
		}
		//a-z,A-Z,0-9のいずれかを含んでいないかチェック
		if (Pattern.compile("(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])").matcher(password).find()) {
			return false;
		}
		return true;
	}

	/**
	 * アカウントリストページを表示します。
	 *
	 * @param modelMap
	 * @return アカウントリストページのリンク
	 */
	@GetMapping("account/list")
	public String accountList(ModelMap modelMap) {
		modelMap.addAttribute("accounts", accounts);
		modelMap.addAttribute("checks", this);
		modelMap.addAttribute("message", "名前横のチェックボックスで選択したデータを削除します。");
		return "d13136/account/list";
	}

	/**
	 * アカウントリストから任意のアカウントを複数削除します。<br>
	 * このメソッドは「削除」ボタンを押したときに実行されます。<br>
	 *
	 * @param modelMap
	 * @param holder 消去するデータのハッシュ値を取り出します。
	 * @return 成績リストページへのリンク
	 */
	@PostMapping("/account/list")
	public String accountList(ModelMap modelMap, @ModelAttribute("checks") D13136Controller holder) {
		String message = "";
		for (String rmHashCode : holder.getHashCodes()) {
			for (D13136Account account : accounts) {
				if (account.hashCode() == Integer.parseInt(rmHashCode)) {
					accounts.remove(account);
					message = message.concat(account.getValue("name") + ",");
					break;
				}
			}
		}
		if (!message.equals("")) {
			message = message.substring(0, message.length() - 1);
			modelMap.addAttribute("message", message + "は消されました。");
			D13136JsonData.writeData(accounts, accountsFile);
		}
		else {
			modelMap.addAttribute("message", "名前横のチェックボックスで選択したデータを削除します。");
		}
		modelMap.addAttribute("accounts", accounts);
		return "d13136/account/list";
	}

	/**
	 * URL検索ページを表示します。
	 *
	 * @param modelMap
	 * @return URL検索ページのリンク
	 */
	@GetMapping("account/searchURL")
	public static String accountSearchURL(ModelMap modelMap) {
		modelMap.addAttribute("message", "検索するURLを入力してください。");
		return "d13136/account/searchURL";
	}

	/**
	 * URL検索をします。<br>
	 * チェックボックスにチェックすると検索したURLと完全一致するURLを持つアカウントを削除します。
	 *
	 * @param modelMap
	 * @param url URL
	 * @return URL検索ページのリンク
	 */
	@PostMapping("account/searchURL")
	public String accountSearchURL(
			ModelMap modelMap,
			@RequestParam("url") String url,
			@RequestParam(value = "isDelete", required = false) boolean isDelete) {
		List<D13136Account> resultList = new ArrayList<>();
		for (D13136Account account : accounts) {
			if (account.getValue("url").equals(url)) {
				resultList.add(account);
			}
		}
		if (isDelete) {
			accounts.removeAll(resultList);
			modelMap.addAttribute("message", url + "を含むアカウントは消されました。");
			D13136JsonData.writeData(accounts, accountsFile);
		}
		else {
			if (!resultList.isEmpty()) {
				modelMap.addAttribute("message", url + "の検索結果");
				modelMap.addAttribute("resultList", resultList);
			}
			else {
				modelMap.addAttribute("message", url + "を含むアカウントは見つかりませんでした。");
			}
		}


		return "/d13136/account/searchURL";
	}

	public List<String> getHashCodes() {
		return hashCodes;
	}

	public void setHashCodes(List<String> hashCodes) {
		this.hashCodes = hashCodes;
	}
}
