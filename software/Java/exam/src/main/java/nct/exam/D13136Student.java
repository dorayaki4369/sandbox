package nct.exam;

import java.lang.reflect.Field;

import org.hibernate.validator.constraints.NotEmpty;

/**
 * 成績保持者(生徒)の名前と英語、国語、数学の3教科の成績、その3教科の成績より得られる解析データを保存します。<br>
 * このクラスより生成されるインスタンスは名前が一致した場合に同じものと判定されます。
 *
 * @author dorayaki4369
 */
@SuppressWarnings("unused")
public class D13136Student implements Comparable<D13136Student> {
	@NotEmpty
	private String name;
	private Integer english;
	private Integer japanese;
	private Integer math;
	private Integer sum;
	private Double avg;

	public D13136Student(String name, int english, int japanese, int math) {
		setName(name);
		setValue("english", english);
		setValue("japanese", japanese);
		setValue("math", math);
		sum = this.english + this.japanese + this.math;
		avg = sum.doubleValue() / 3;
	}

	public void setName(String name) {
		if (name.length() == 0) {
			name = "unknown";
		}
		this.name = name;
	}

	/**
	 * フィールド名を検索し、合致した場合にフィールドの値を書き換えます。<br>
	 * 値が整数以外で、0~100以外の場合は強制的に0に書き換わります。
	 *
	 * @param name フィールド名
	 * @param value 値
	 */
	public void setValue(String name, Integer value) {
		try {
			Field field = this.getClass().getDeclaredField(name);
			field.setAccessible(true);
			if (value < 0 || value > 100) {
				System.err.println(name + "の値が不正です : " + value);
				value = 0;
			}
			field.set(this, value);
		}
		catch (NoSuchFieldException | SecurityException | IllegalArgumentException | IllegalAccessException e) {
			e.printStackTrace();
		}
	}

	/**
	 * フィールド名を検索し、合致した場合にフィールドの値を取り出します。<br>
	 *
	 * @param name フィールド名
	 * @return フィールド内部のデータ
	 */
	public Object getValue(String name) {
		try {
			Field field = this.getClass().getDeclaredField(name);
			return field.get(this);
		}
		catch (NoSuchFieldException | SecurityException | IllegalArgumentException | IllegalAccessException e) {
			e.printStackTrace();
		}
		return null;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((name == null) ? 0 : name.hashCode());
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj) return true;
		if (obj == null) return false;
		if (getClass() != obj.getClass()) return false;
		D13136Student other = (D13136Student) obj;
		if (name == null) {
			if (other.name != null) return false;
		}
		else if (!name.equals(other.name)) return false;
		return true;
	}

	@Override
	public int compareTo(D13136Student o) {
		if (this.equals(o)) {
			return 0;
		}
		else if (this.hashCode() > o.hashCode()) {
			return 1;
		}
		return -1;
	}
}
