package part1;

public class Chapter36 {
	public static void main(String[] args) {
		System.out.println("[数あてゲーム]");
		int ans = new java.util.Random().nextInt(10);

		for (int i = 0; i < 5; i++) {
			System.out.println("0～9の数字を入れてください");
			@SuppressWarnings("resource")
			int num = new java.util.Scanner(System.in).nextInt();
			if (ans == num) {
				System.out.println("アタリ！");
				break;
			}
			System.out.println("駄目です");
		}
		System.out.println("ゲームを終了します");
	}
}
