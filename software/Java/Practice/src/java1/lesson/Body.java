package lesson;

public class Body {
	private double height;
	private double weight;

	public Body() {
		this.height = Math.random();
		this.weight = Math.random();
	}

	public Body(double height, double weight) {
		this.height = height;
		this.weight = weight;
	}

	public double getBmi() {
		double bmi = this.weight / (this.height * this.height);
		return bmi;
	}

	public double getHeight() {
		return this.height;
	}

	public void setHeight(double height) {
		this.height = height;
	}

	public void setHightAsCm(double cm) {
		this.height = cm / 100;
	}

	public double getWeight() {
		return this.weight;
	}

	public void setWeight(double weight) {
		this.weight = weight;
	}
}
