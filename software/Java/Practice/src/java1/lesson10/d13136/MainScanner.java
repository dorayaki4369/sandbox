package lesson10.d13136;

import java.util.Scanner;

public class MainScanner {
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		while (true) {
			System.out.println("入力してください: a");
			String input = scanner.next();
			if (input.equals("quit")) {
				break;
			}
			System.out.println("入力された文字: " + input);
		}
	}
}
