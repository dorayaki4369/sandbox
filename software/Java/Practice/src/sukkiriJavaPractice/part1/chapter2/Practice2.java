package part1.chapter2;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Practice2 {
	public static void main(String[] args) {
		LocalDate now = LocalDate.now();
		LocalDate future = now.plusDays(100);
		DateTimeFormatter formatter = DateTimeFormatter.ofPattern("西暦yyyy年MM月dd日");

		System.out.println(future.format(formatter));
	}
}
