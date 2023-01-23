package part1.chapter5;

public class StrongBox<E> {
	private E item;
	private KeyType keyType;
	private long count;

	public StrongBox(KeyType keyType) {
		this.keyType = keyType;
	}

	public void put(E item) {
		this.item = item;
	}

	public E get() {
		this.count++;
		switch (this.keyType) {
		case PADLOCK:
			if (this.count <= 1024)
				return null;

		case BUTTON:
			if (this.count <= 10000)
				return null;

		case DIAL:
			if (this.count <= 30000)
				return null;

		case FINGER:
			if (this.count <= 1000000L)
				return null;
		}

		this.count = 0;
		return this.item;
	}

}
