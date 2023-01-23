package part1.chapter6;

interface Func1 {
	boolean call(int x);
}

interface Func2 {
	String call(boolean male, String name);
}

public class Main {
	public static void main(String[] args) {
		Func1 func1 = FuncList::isOdd;
		Func2 func2 = FuncList::addNamePrefix;
		System.out.println(func1.call(15));
		System.out.println(func2.call(true, "Smith"));
	}
}
