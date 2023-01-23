package part1.chapter3;

import java.util.HashMap;
import java.util.Map;

public class Practice3 {
	public static void main(String[] args) {
		Map<Hero, Integer> heroes = new HashMap<Hero, Integer>();
		Hero h1 = new Hero("斎藤");
		Hero h2 = new Hero("鈴木");

		heroes.put(h1, 3);
		heroes.put(h2, 7);

		for (Hero key : heroes.keySet()) {
			System.out.println(key.getName() + "が倒した敵 = " + heroes.get(key));
		}
	}
}
