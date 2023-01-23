package lesson09.p1;

import java.util.ArrayList;
import java.util.List;

import lesson05.d13136.Book;

public class MainList {
	public static void main(String[] args) {
		List<Book> bookList = new ArrayList<>();

		Book book1 = new Book("hoge", "huga", 100);
		bookList.add(book1);
		bookList.add(new Book("foo", "bar", 2000));
		System.out.println(bookList.size() + "冊");

		bookList.clear();
	}
}