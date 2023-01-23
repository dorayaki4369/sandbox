package practice2.d13136.p2;

public class UnitedStatesDollar implements YenEquivalent {
	public static final int EXCAHNGE_RATE_YEN = 112;
	public int amount;

	public UnitedStatesDollar(int amount) {
		this.amount = amount;
	}

	@Override
	public int genYen() {
		return amount * EXCAHNGE_RATE_YEN;
	}
}
