package stream;

import java.util.ArrayList;
import java.util.List;

public class Main {
	public static void main(String[] args) {
		List<String> cityName = new ArrayList<>();
		cityName.add("Tokyo");
		cityName.add("Osaka");
		cityName.add("Nagoya");
		cityName.add("Sapporo");
		cityName.add("Naha");

		//***
		//全ての要素を出力
		//***
		//従来の書き方
		for (String string : cityName) {
			System.out.println(string);
		}
		System.out.println();
		//Java8の書き方
		cityName.stream().forEach(System.out::println);
		System.out.println();


		//***
		//Nで始まる要素のみ出力
		//***
		//従来の書き方
		for (String string : cityName) {
			if (string.startsWith("N")) {
				System.out.println(string);
			}
		}
		System.out.println();
		//Java8の書き方
		cityName.stream()
				.filter(s -> s.startsWith("N"))
				.forEach(System.out::println);
		System.out.println();
	}
}
