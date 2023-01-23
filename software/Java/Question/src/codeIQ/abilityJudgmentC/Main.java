/**
 * 「0123456789」の10枚のカードの内、4枚のカードが提示されます。
 * 通常は、「最も数値が大きなカード」が勝利者のカードです。
 * 4枚の中に0があれば、「0以外で最も小さなカード」が勝利者のカードです。
 * 勝利者のカードの数値を割り出してください。
 */
package abilityJudgmentC;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner cin = new Scanner(System.in);
		String line;
		for (; cin.hasNext();) {
			line = cin.nextLine();
			boolean sw = (line.indexOf("0") == -1) ? true : false;
			int num = (sw) ? 0 : 9;
			for (int i = 1; i <= 9; i++) {
				if (line.indexOf(String.valueOf(i)) != -1) {
					if (sw) {
						num = Math.max(num, i);
					}
					else {
						num = Math.min(num, i);
					}
				}
			}
			System.out.println(num);
		}
	}
}
