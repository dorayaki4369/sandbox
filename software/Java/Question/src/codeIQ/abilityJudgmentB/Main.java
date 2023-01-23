package abilityJudgmentB;

import java.util.Scanner;

/**
 * 一番左の桁を先頭として、右の桁へと順に見ていきます。<br>
 * そして、隣り合った数が連続する数だった場合は、その双方を削除して先頭に戻ります。<br>
 * 最終的に、削除ができなくなった時点で数字を出力します。<br>
 * <br>
 * 例<br>
 * 9"54"22357545868773174<br>
 * 92"23"57545868773174<br>
 * 9257"54"5868773174<br>
 * 9257586"87"73174<br>
 * 925758"67"3174<br>
 * 9257583174(正答)<br>
 *
 * @author dorayaki4369
 */
public class Main {
	public static void main(String[] args) {
		String line;
		String tempLine[] = new String[2];
		int[] number = new int[3];
		@SuppressWarnings("resource")
		Scanner cin = new Scanner(System.in);

		while (cin.hasNext()) {
			line = new String(cin.nextLine());

			//検査する値と"ひとつ後の"値を比較する
			//"ひとつ後の"が重要で、"ひとつ前の"では"7867"みたいな最初に連続して出てくる数字のペアに対応できない
			for (int i = 0; i < line.length(); i++) {
				if (i == 0) {
					continue;
				}
				number[0] = Character.getNumericValue(line.charAt(i));
				number[1] = Character.getNumericValue(line.charAt(i - 1));

				if (number[1] == number[0] - 1 || number[1] == number[0] + 1) {
					tempLine[0] = line.substring(0, i - 1);
					tempLine[1] = line.substring(i + 1);
					line = tempLine[0] + tempLine[1];
					i = 0;//もっといい方法があるはずだが問題で指定されているため
				}
			}
			System.out.println(line);
		}
	}
}
