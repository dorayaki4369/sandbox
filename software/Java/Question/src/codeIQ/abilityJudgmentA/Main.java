package abilityJudgmentA;

import java.util.Scanner;

/**
 * 1から1,000,000までの整数の範囲で、連続する2値を合計します。
 * 2値の合計が、整数Nの倍数になる組み合わせを、数えてください。
 * ただし、整数Nは、2≦N≦1,000 の範囲とします。
 *
 * 解説
 * 指定された範囲の連続する2つの整数の合計は、3,5,7,...のように増えていき、必ず奇数になります。
 * そのため、整数Nが偶数の場合は、整数Nの倍数の個数は、必ず0になります。
 * 奇数の場合は、「1999999 / N」の端数を切り捨てた値をMとして、「M / 2」の端数を切り上げた値になります。
 *
 * @author dorayaki4369
 */
public class Main {
	static int counter = 0;
	static int n;

	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner cin = new Scanner(System.in);

		while (cin.hasNext()) {
			n = Integer.valueOf(cin.nextLine());
			//下の解法より時間のかかるやり方
			for (int i = n; i < 2000000; i = i + n) {
				if (i % 2 != 0) {
					counter++;
				}
			}
			System.out.println(counter);
			counter = 0;
		}
	}
}

