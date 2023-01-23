package stream;

public class Sweets implements Product {
	String name;
	int price;
	int calorie;

	public Sweets(String name, int calorie, int price) {
		this.name = name;
		this.calorie = calorie;
		this.price = price;
	}

	@Override
	public String getInfomation() {
		return this.name + this.calorie + this.price;
	}

	@Override
	public String getFormatInfomation() {
		return String.format("品名:%5s,カロリー:%5s,値段:%5s", this.name, this.calorie, this.price);
	}
}
