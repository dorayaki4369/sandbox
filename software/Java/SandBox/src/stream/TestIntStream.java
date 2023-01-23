package stream;

import java.util.stream.IntStream;

/**
 * Intstreamとfor文の速さを比較
 * 結果はfor文のほうが80倍くらい速かった
 *
 * @author ryuya
 */
public class TestIntStream {
	public static void main(String[] args) {
		long startF = System.currentTimeMillis();
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					System.out.println(i + j + k);
				}
			}
		}
		long endF = System.currentTimeMillis();

		long startI = System.currentTimeMillis();
		IntStream.range(0, 3).parallel().forEach(i -> {
			IntStream.range(0, 3).parallel().forEach(j -> {
				IntStream.range(0, 3).parallel().forEach(k -> {
					System.out.println(i + j + k);
				});
			});
		});
		long endI = System.currentTimeMillis();

		//計測時間出力
		System.out.println("for_time:" + (endF - startF) + "ms");
		System.out.println("str_time:" + (endI - startI) + "ms");
	}
}
