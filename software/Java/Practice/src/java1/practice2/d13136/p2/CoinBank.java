package practice2.d13136.p2;

import java.util.HashSet;
import java.util.Set;

public class CoinBank {
	private Set<YenEquivalent> money = new HashSet<>();
	private int total = 0;

	public void put(YenEquivalent money) {
		this.money.add(money);
	}

	public int getTotal() {
		money.parallelStream().forEach(money -> total += money.genYen());
		return total;
	}
}
