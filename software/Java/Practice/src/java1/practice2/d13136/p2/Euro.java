package practice2.d13136.p2;

public class Euro implements YenEquivalent {
	public static final int EXCANGE_RATE_YEN = 120;
	public int amount;

	public Euro(int amount) {
		this.amount = amount;
	}

	@Override
	public int genYen() {
		return amount * EXCANGE_RATE_YEN;
	}
}
