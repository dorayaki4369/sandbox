package practice2.d13136.p2;

public class JapaneseYen implements YenEquivalent {
	public int amount;

	public JapaneseYen(int amount) {
		this.amount = amount;
	}

	@Override
	public int genYen() {
		return amount;
	}
}
