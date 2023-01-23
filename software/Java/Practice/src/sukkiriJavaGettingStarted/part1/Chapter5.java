package part1;

public class Chapter5 {
	public static void main(String[] args) {
		email("ryuyaman@gmail.com", "ありがとウサギ");
		email("こんにちワニ", "ryuyaman@gmail.com", "さよなライオン");

		introduceOneself();

		double s1 = calcCircleArea(3);
		double s2 = calcTriangleArea(4, 5);

		System.out.println(s1);
		System.out.println(s2);
	}

	public static void introduceOneself() {
		String name = "ryuuya";
		int age = 19;
		double height = 176.6;
		char sex = '男';

		System.out.println("私の名前は" + name + "です。歳は" + age + "です。" + "性別は" + sex + "で、身長は" + height + "です。");

	}

	public static void email(String title, String address, String text) {
		System.out.println( address + "に、以下のメールを送信しました。");
		System.out.println("件名:" + title);
		System.out.println("本文:" + text);
	}

	public static void email(String address, String text) {
		System.out.println(address + "に、以下のメールを送信しました。");
		System.out.println("件名:無題");
		System.out.println("本文:" + text);
	}

	public static double calcTriangleArea(double bottom, double height) {
		double s = bottom * height / 2;

		return s;
	}

	public static double calcCircleArea(double radius) {
		double s = radius * radius * 3.14;

		return s;
	}
}