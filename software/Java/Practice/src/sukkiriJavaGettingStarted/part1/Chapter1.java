package part1;

public class Chapter1 {
	public static void main(String[] args) {
		int a = 3;
		int b = 5;
		int c = a * b;

		System.out.println("縦幅" + a + "横幅" + b + "の長方形の面積は" + c);

		boolean result = true;
		char favoriteCharactor = '駆';
		double pi = 3.14;
		long number = 314159265853979L;
		String msg = "ミナトの攻撃！　敵に15ポイントのダメージを与えた。";

		if (result = true) {
			System.out.println(result);
			System.out.println(favoriteCharactor);
			System.out.println(pi);
		} else {
			System.out.println(number);
		}
		System.out.println(msg);
	}
}
