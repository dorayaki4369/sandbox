package part2;

public class Book extends TangibleAsset {
	private String isbn;

	public Book(String name, int price, String color, String isbn) {
		super(name, price, color);
		this.isbn = isbn;
	}

	public String getIsbn() {
		return isbn;
	}

	@Override
	public double getWeight() {
		return 0;
	}
}