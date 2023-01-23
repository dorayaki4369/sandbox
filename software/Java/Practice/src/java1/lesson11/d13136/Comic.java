package lesson11.d13136;

public class Comic extends Book {
	private int volume;

	public Comic(String title, String author, int price, int volume) {
		super(title, author, price);
		this.volume = volume;
	}

	@Override
	public String toString() {
		return super.toString();
	}

	@Override
	public String getInfo() {
		return super.getInfo() + "," + this.volume + "巻";
	}
}
