package part1.chapter2;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class Practice1 {
	public static void main(String[] args) {
		Date now = new Date();
		Calendar calendar = Calendar.getInstance();
		calendar.setTime(now);

		int day = calendar.get(Calendar.DAY_OF_MONTH);

		day += 100;
		calendar.set(Calendar.DAY_OF_MONTH, day);

		Date future = calendar.getTime();

		SimpleDateFormat f = new SimpleDateFormat("西暦yyyy年MM月dd日");
		System.out.println(f.format(future));


	}
}
