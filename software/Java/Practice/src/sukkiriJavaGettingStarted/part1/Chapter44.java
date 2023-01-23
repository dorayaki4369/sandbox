package part1;

public class Chapter44 {
	public static void main(String[] args) {
		int[] numbers = { 3, 4, 9 };
		System.out.println("1桁の数字を入力してください");

		@SuppressWarnings("resource")
		int input = new java.util.Scanner(System.in).nextInt();

		for (int i : numbers) {
			if (i == input) {
				System.out.println("アタリ!");
			}
		}
	}
}
