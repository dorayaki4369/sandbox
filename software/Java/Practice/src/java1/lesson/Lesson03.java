package lesson;

import lesson05.d13136.Seiseki;

public class Lesson03 {
	public static void main(String[] args) {
		Body taro = new Body(1.7, 70.0);
		System.out.println("太郎のBMIは" + taro.getBmi() + "です。");

		Seiseki ziro = new Seiseki(8, 2, 3, 4, 5);

		System.out.println(ziro.getTotal());
	}
}
