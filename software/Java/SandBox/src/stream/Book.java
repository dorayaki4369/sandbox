package stream;

public class Book implements Product {
	String name;
	String autor;
	int price;

	public Book(String name, String autor, int price) {
		this.name = name;
		this.autor = autor;
		this.price = price;
	}

	@Override
	public String getInfomation() {
		return this.name + this.autor + this.price;
	}

	@Override
	public String getFormatInfomation() {
		return String.format("品名:%5s,著者:%5s,値段:%5s", this.name, this.autor, this.price);
	}
}
