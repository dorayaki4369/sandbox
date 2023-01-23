package lesson11.d13136;

import java.util.ArrayList;
import java.util.List;

public class Main {
	public static void main(String[] args) {
		CashRegister cashRegister = new CashRegister();
		cashRegister.addProduct(new Book("Java逆引きレシピ", "竹添他", 2800));
		cashRegister.addProduct(new Comic("ドラゴンボール", "鳥山", 500, 1));
		cashRegister.addProduct(new BoxedLunch("のり弁当", 100, 300));
		cashRegister.printReceipt();
		cashRegister.clear();

		List<Book> bookList = new ArrayList<Book>();
		bookList.add(new Book("Java逆引きレシピ", "竹添他", 2800));
		bookList.add(new Book("Kotlinスタートブック", "長澤", 3500));
		bookList.add(new Comic("ドラゴンボール", "鳥山", 500, 1));
		bookList.add(new Comic("ドラゴンボール", "鳥山", 500, 2));

		int totalPrice1 = 0;
		for (Book b : bookList) {
			totalPrice1 += b.getPrice();
		}
		for (Book b : bookList) {
			System.out.println(b.toString());
		}
		System.out.println("合計金額は" + totalPrice1 + "円です。");
	}
}
