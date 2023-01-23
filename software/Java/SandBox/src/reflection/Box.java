package reflection;

import java.lang.reflect.Field;

@SuppressWarnings("unused")
public class Box {
	private int x;
	private int y;
	private int z;

	public Box(int x, int y, int z) {
		setValue("x", x);
		setValue("y", y);
		setValue("z", z);
	}

	public void setValue(String name, int value) {
		try {
			Field field = this.getClass().getDeclaredField(name);
			field.setAccessible(true);
			field.set(this, value);
		}
		catch (NoSuchFieldException | SecurityException | IllegalArgumentException | IllegalAccessException e) {
			e.printStackTrace();
		}
	}

	public int getValue(String name) {
		try {
			Field field = this.getClass().getDeclaredField(name);
			return field.getInt(this);
		}
		catch (NoSuchFieldException | SecurityException | IllegalArgumentException | IllegalAccessException e) {
			e.printStackTrace();
		}
		return 0;
	}
}
