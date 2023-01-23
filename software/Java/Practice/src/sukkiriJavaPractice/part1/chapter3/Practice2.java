package part1.chapter3;

import java.util.ArrayList;
import java.util.List;

public class Practice2 {
	public static void main(String[] args) {
		List<Hero> heroes = new ArrayList<>();
		Hero h1 = new Hero("斎藤");
		Hero h2 = new Hero("鈴木");

		heroes.add(h1);
		heroes.add(h2);

		for (Hero hero : heroes) {
			System.out.println(hero.getName());
		}
	}
}
