package lesson09.p1;

import lesson05.d13136.Book;

public class MainArray {
	public static void main(String[] args) {
		int[] a = new int[5];
		for (int i : a) {
			System.out.println(a[i]);
		}

		@SuppressWarnings("unused")
		Book[] bookArray = {new Book("hoge","huga",100),new Book("foo","bar",2000)};
		Book[] onePiece = new Book[50];

		for (int i = 0; i < onePiece.length; i++) {
			onePiece[i] = new Book("onePiece" + i + "巻", "OdaEichiro", 800);
		}
	}
}
