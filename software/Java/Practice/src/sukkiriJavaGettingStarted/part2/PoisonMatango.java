package part2;

public class PoisonMatango extends Matango {
	private int poisonCount = 5;

	public PoisonMatango(char suffix) {
		super(suffix);
	}

	@Override
	public void attack(Hero h) {
		super.attack(h);
		if (this.poisonCount != 0) {
			System.out.println("さらに毒の胞子をばらまいた！");
			int damageCount = h.getHp() / 5;
			h.setHp(h.getHp() - damageCount);
			System.out.println(damageCount + "ポイントのダメージ");
			this.poisonCount--;
		}
	}

	public int getPoisonCount() {
		return poisonCount;
	}

	public void setPoisonCount(int poisonCount) {
		this.poisonCount = poisonCount;
	}

}
