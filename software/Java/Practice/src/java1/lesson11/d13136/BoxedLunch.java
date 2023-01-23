package lesson11.d13136;

public class BoxedLunch implements Product {
	private String name;
	private int price;
	@SuppressWarnings("unused")
	private int gram;

	public BoxedLunch(String name, int price, int gram) {
		this.name = name;
		this.price = price;
		this.gram = gram;
	}

	@Override
	public int getPrice() {
		return this.price;
	}

	@Override
	public String getName() {
		return this.name;
	}

}
