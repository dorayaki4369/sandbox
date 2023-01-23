package lesson05.d13136;

public class Book {
	private String title;
	private String author;
	private int price;

	public Book(String title, String author, int price) {
		setTitle(title);
		setAuthor(author);
		setPrice(price);
	}

	public void printInfo() {
		System.out.println("タイトル	：" + this.title);
		System.out.println("著者		：" + this.author);
		System.out.println("税抜き価格	：" + this.price);
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public void setAuthor(String author) {
		this.author = author;
	}

	public void setPrice(int price) {
		this.price = price;
	}
}
