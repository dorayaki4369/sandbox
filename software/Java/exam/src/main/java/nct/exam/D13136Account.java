package nct.exam;

import java.lang.reflect.Field;

/**
 * アカウント情報を保存します。<br>
 * このクラスのインスタンスは名前が一致した場合に等価とされます。
 * 保存される情報はパスワードとURLです。<br>
 * アカウント名(ユーザー名)は保存しないので、Mapを使用して一緒に保存するようにしてください。
 *
 * <pre>
 * {@code
 * Map<String, D13136AccountInfo> accounts = new HashMap()<>;
 * }
 * </pre>
 *
 * @author dorayaki4369
 */

@SuppressWarnings("unused")
public class D13136Account implements Comparable<D13136Account> {
	private String name;
	private String password;
	private String url;

	public D13136Account(String name, String password, String url) {
		this.name = name;
		this.password = password;
		this.url = url;
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
		D13136Account other = (D13136Account) obj;
		if (name == null) {
			if (other.name != null) return false;
		}
		else if (!name.equals(other.name)) return false;
		return true;
	}

	@Override
	public int compareTo(D13136Account o) {
		if (this.equals(o)) {
			return 0;
		}
		else if (this.hashCode() > o.hashCode()) {
			return 1;
		}
		return -1;
	}
}
