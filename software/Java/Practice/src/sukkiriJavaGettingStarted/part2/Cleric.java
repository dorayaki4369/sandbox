package part2;

import java.util.Random;

//カプセル化なし

public class Cleric {
	String name;
	int hp = 50;
	int mp = 10;
	static final int MAX_HP = 50;
	static final int MAX_MP = 10;

	public void selfAid() {
		System.out.println(this.name + "はセルフエイドを唱えた!");
		this.hp = Cleric.MAX_HP;
		this.mp -= 5;
		System.out.println("HPが最大まで回復した。");
	}

	public int pray(int sec) {
		System.out.println(this.name + "は" + sec + "秒間天に祈った！");

		int recover = new Random().nextInt(3) + sec;

		int recoverActual = Math.min(Cleric.MAX_MP - this.mp, recover);

		this.mp += recoverActual;
		System.out.println("MPが" + recoverActual + "回復した。");
		return recoverActual;
	}

	Cleric(String name, int hp, int mp) {
		this.name = name;
		this.hp = hp;
		this.mp = mp;
	}

	Cleric(String name, int hp) {
		this(name, hp, Cleric.MAX_MP);
	}

	Cleric(String name) {
		this(name, Cleric.MAX_HP, Cleric.MAX_MP);
	}
}