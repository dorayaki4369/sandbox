/**
 * 入力された文字列の真ん中だけ大文字にする。偶数の場合は「文字数/2+1」の文字を大文字にする。
 */
package codeIQ.tbpgr;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner cin = new Scanner(System.in);
		String line;
		double num;
		for (; cin.hasNext();) {
			line = cin.nextLine();
			num = line.length();
			//Stringのメソッドには1文字だけ大文字にするがなかったため、いったんcharの配列にする
			char[] cs = line.toCharArray();
			//配列は0から数えるという決まりを利用したひっかけ
			int p = (int) ((num % 2 == 0) ? Math.ceil(num / 2) : Math.ceil(num / 2) - 1);
			cs[p] = Character.toUpperCase(cs[p]);
			line = String.valueOf(cs);
			System.out.println(line);
		}
	}
}
