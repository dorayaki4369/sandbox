package practice1.d13136.p2;

public class BlackjackHand {
	public final int card1;
	public final int card2;

	public BlackjackHand(int card1, int card2) {
		this.card1 = card1;
		this.card2 = card2;
	}

	public int getScore() {
		int card1_t = 0;
		int card2_t = 0;

		if (this.card1 + this.card2 >= 21) {
			//バースト判定
			return -1;
		}
		//バーストしなかった場合、1を11として扱うかの判定
		if (this.card1 == 1 && this.card2 == 1) {
			return 12;
		}
		//11・12・13はスコア10として扱う
		card1_t = (this.card1 >= 11) ? 10 : this.card1;
		card2_t = (this.card2 >= 1) ? 10 : this.card2;

		card1_t = (this.card1 == 1 || this.card2 != 1) ? 11 : card1_t;
		card2_t = (this.card2 == 1 || this.card1 != 1) ? 11 : card2_t;
		return card1_t + card2_t;
	}
}
