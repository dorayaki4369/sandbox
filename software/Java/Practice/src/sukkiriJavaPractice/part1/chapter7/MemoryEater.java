package part1.chapter7;

public class MemoryEater {
	public static void main(String[] args) {
		System.out.println("Eating Memory...");
		long[] longArray = new long[1280000];

		for (int i = 0; i < longArray.length; i++) {
			longArray[i] = i;
		}
	}
}
