package part2;

public abstract class TangibleAsset extends Asset implements Thing {
	private String color;
	@SuppressWarnings("unused")
	private double weight;

	public TangibleAsset(String name, int price, String color) {
		super(name, price);
		this.color = color;
	}

	public String getColor() {
		return color;
	}

	@Override
	public void setWeight(double weight) {
		this.weight = weight;
	}
}
