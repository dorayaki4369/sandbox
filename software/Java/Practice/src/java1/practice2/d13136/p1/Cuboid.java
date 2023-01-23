package practice2.d13136.p1;

public class Cuboid extends Rectangle {
	public int z;

	public Cuboid(int x, int y) {
		super(x, y);
		this.z = 1;
	}

	public Cuboid(int x, int y, int z) {
		super(x, y);
		this.z = z;
	}

	public int getVolume() {
		return x * y * z;
	}

	@Override
	public int getArea() {
		return 2 * (x * y + x * z + y * z);
	}
}
