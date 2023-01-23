package section1;

import java.util.LinkedHashMap;
import java.util.Map;

public class Q03_1 {
	public static void main(String[] args) {
		Map<String, Boolean> card = new LinkedHashMap<>();
		for (int i = 1; i <= 100; i++) {
			card.put(String.valueOf(i), false);
		}

		for (int i = 2; i <= card.size(); i++) {
			for (int j = i; j <= card.size(); j += i) {
				String key = String.valueOf(j);
				card.put(key, !card.get(key));
			}
		}

		for (String num : card.keySet()) {
			if (!card.get(num)) {
				System.out.println(num + ",");
			}
		}
	}
}
