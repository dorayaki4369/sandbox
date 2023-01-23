package lesson10.d13136;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MainCalc {
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		List<Integer> numList = new ArrayList<>();

		//数字を入力
		while (true) {
			System.out.println("数値かquitを入力");
			String input = scanner.next();
			if (input.equals("quit")) {
				break;
			}
			//int num = Integer.parseInt(input);
			numList.add(Integer.parseInt(input));
		}

		//和と積を計算して表示する
		int sum = 0;
		int product = 1;
		for (int i = 0; i < numList.size(); i++) {
			int num = numList.get(i);
			sum += num;
			product *= num;
		}
		System.out.println("和: " + sum);
		System.out.println("積: " + product);
	}
}
