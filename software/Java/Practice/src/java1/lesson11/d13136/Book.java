package lesson11.d13136;

public class Book implements Product{
	private String title;
	private String author;
	private int price;

	public Book(String title, String author, int price) {
		this.title = title;
		this.author = author;
		this.price = price;
	}

	@Override
	public String toString() {
		return getInfo();
	}

	public String getInfo() {
		return String.format("%-20s,%-10s,%5s円", this.title, this.author,this.getPrice());
	}

	public void printInfo() {
		System.out.println("タイトル	：" + this.title);
		System.out.println("著者		：" + this.author);
		System.out.println("税抜き価格	：" + this.getPrice());
	}

	@Override
	public String getName() {
		return title;
	}

	@Override
	public int getPrice() {
		return price;
	}
}
