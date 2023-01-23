package lesson11.d13136;

import java.util.ArrayList;
import java.util.List;

public class CashRegister {
	private List<Product> productArray;

	public CashRegister() {
		this.productArray = new ArrayList<Product>();
	}

	public void addProduct(Product p) {
		this.productArray.add(p);
	}

	public void clear() {
		this.productArray.clear();
	}

	public void printReceipt() {
		int total = 0;
		for (Product p : productArray) {
			System.out.printf("%-10s%5s円\n",p.getName(),p.getPrice());
			total += p.getPrice();
		}
		int tax = (int) (0.08 * total);
		System.out.println("------------------------");
		System.out.printf("小計%5s円\n",total);
		System.out.printf("税  %5s円\n",tax);
		System.out.printf("合計%5s円\n",(total + tax));
	}
}
