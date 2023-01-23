package part1.chapter7;

import java.lang.reflect.Method;

public class Launcher {
	public static void main(String[] args) {
		String FQCN = args[0];
		String boot = args[1];

		showUsageMemory();

		try {
			Class<?> clazz = Class.forName(FQCN);
			showMethodName(clazz);

			if (boot.equals("I")) {
				launchExternal(clazz);
			}
			else if (boot.equals("E")) {
				launchInternal(clazz);
			}
			else {
				throw new IllegalArgumentException("起動方法が不正です : " + boot);
			}
		}
		catch (Exception e) {
			System.out.println(e.getMessage());
			e.printStackTrace();
			System.exit(1);
		}
		showUsageMemory();
		System.exit(0);
	}

	/**
	 * 引数で与えられたクラスのメソッドを全て表示します。
	 *
	 * @param clazz
	 */
	public static void showMethodName(Class<?> clazz) {
		System.out.println("メソッドの一覧を表示します");
		Method[] methods = clazz.getDeclaredMethods();
		for (Method method : methods) {
			System.out.println(method.getName());
		}
	}

	/**
	 * 与えられたクラスを別プロセスとして起動します。
	 *
	 * @param clazz
	 * @throws Exception
	 */
	public static void launchExternal(Class<?> clazz) throws Exception {
			ProcessBuilder pb = new ProcessBuilder("Java", clazz.getName());
			Process process = pb.start();
			process.waitFor(); //プロセス終了まで待つ
	}

	/**
	 * 与えられたクラスのmainメソッドを起動します。
	 *
	 * @param clazz
	 * @throws Exception
	 */
	public static void launchInternal(Class<?> clazz) throws Exception {
		Method method = clazz.getMethod("main", String[].class);
		String[] args = {};
		method.invoke(null, (Object) args);
	}

	/**
	 * 現在のメモリ使用量をMB単位で表示します。
	 */
	public static void showUsageMemory() {
		long free = Runtime.getRuntime().freeMemory();
		long total = Runtime.getRuntime().totalMemory();
		long usage = (total - free) / 1024 / 1024;
		System.out.println("現在のメモリ使用量:" + usage + "MB");
	}
}
