package part1.chapter6;

public class FuncList {
	public static boolean isOdd(int x) {
		return (x % 2 == 1);
	}

	public static String addNamePrefix(boolean male, String name) {
		if (male) {
			return "Mr." + name;
		}
		return "Ms." + name;
	}
}
