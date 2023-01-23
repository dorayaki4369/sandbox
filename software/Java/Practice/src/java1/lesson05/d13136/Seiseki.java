package lesson05.d13136;

import java.util.LinkedHashMap;
import java.util.Map;

public class Seiseki {
	private Map<String, Integer> seisekiData = new LinkedHashMap<String, Integer>();
	@SuppressWarnings("unused")
	private Map<String, Map<String, Integer>> NameAndSeiseki = new LinkedHashMap<String, Map<String,Integer>>();


	public Seiseki(int en, int ja, int ma, int sc, int so) {
		//NameAndSeiseki.put("aa", seisekiData.put("english", en));
		seisekiData.put("english", en);
		seisekiData.put("Japanese", ja);
		seisekiData.put("Math", ma);
		seisekiData.put("science", sc);
		seisekiData.put("social", so);

		for (String key : seisekiData.keySet()) {
			errorMap(seisekiData.get(key), key);
		}
	}

	public Seiseki() {
		int seiseki = new java.util.Random().nextInt(6);
		seiseki++;
		seisekiData.put("english", seiseki);
		seisekiData.put("Japanese", seiseki);
		seisekiData.put("Math", seiseki);
		seisekiData.put("science", seiseki);
		seisekiData.put("social", seiseki);
	}

	public int getTotal() {
		int total = 0;
		for (String key : seisekiData.keySet()) {
			total = +seisekiData.get(key);
		}
		return total;
	}

	public double getAverage() {
		double Average = (double) getTotal() / 5;
		return Average;
	}

	public void getList(String name) {
		System.out.printf("%-6sの成績一覧\n", name);
		for (String key : seisekiData.keySet()) {
			System.out.printf("%-10s	:%d\n", key, seisekiData.get(key));
		}
	}

	//setterメソッド
	public static int setEnglish(int english) {
		error(english);
		return english;
	}

	public static int setJapanese(int japanese) {
		error(japanese);
		return japanese;
	}

	public static int setMath(int math) {
		error(math);
		return math;
	}

	public static int setScience(int science) {
		error(science);
		return science;
	}

	public static int setSocial(int social) {
		error(social);
		return social;
	}

	public static void error(int value) {
		if (value < 1 || value > 5) {
			throw new IllegalArgumentException(value + "の数字が入力されました。1~5の整数を入力してください。");
		}
	}

	public static void errorMap(int value, String key) {
		if (value <= 0 || value > 5) {
			throw new IllegalArgumentException(key + "の教科で" + value + "が入力されました。1~5の整数を入力してください。");
		}
	}
}
