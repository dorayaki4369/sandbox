package practice1.d13136.p1;

public class Rectangle {
	public int width;
	public int height;

	public Rectangle(int width, int height) {
		this.width = width;
		this.height = height;
	}

	public int getArea() {
		return this.height * this.width;
	}

	public boolean isSquare() {
		return this.height == this.width;
	}
}
