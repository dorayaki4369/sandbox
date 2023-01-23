package section1;

//高速バージョン
public class Q03_2 {
	public static void main(String[] args) {
		for (int i = 1; i <= 100; i++) {
			boolean flag = false;
			for (int j = 1; j <= 100; j++) {
				if (i % j == 0) {
					flag = !flag;
				}
			}
			if (flag) {
				System.out.println(i + ",");
			}
		}
	}
}
