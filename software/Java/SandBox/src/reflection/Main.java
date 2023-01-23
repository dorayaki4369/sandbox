package reflection;

public class Main {
	public static void main(String[] args) {
		Box box = new Box(1, 2, 3);
		System.out.println(box.getValue("y"));
	}
}
