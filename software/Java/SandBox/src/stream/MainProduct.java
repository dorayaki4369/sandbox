package stream;

import java.util.ArrayList;
import java.util.List;

public class MainProduct {
	public static void main(String[] args) {
		List<Product> prductList = new ArrayList<>();
		prductList.add(new Book("山月記", "中島敦", 100));
		prductList.add(new Sweets("ポッキー", 146000, 98));

		//従来の書き方
		for (Product product : prductList) {
			System.out.println(product.getFormatInfomation());
		}
		System.out.println();
		//Java8での書き方
		prductList.stream()
				.map(p -> p.getFormatInfomation())
				.forEach(System.out::println);
	}
}
