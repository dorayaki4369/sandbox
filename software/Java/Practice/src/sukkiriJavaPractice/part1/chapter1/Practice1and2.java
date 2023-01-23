package part1.chapter1;

public class Practice1and2 {
	public static void main(String[] args) {
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= 100; i++) {
			sb.append(i).append(",");
		}
		String s = sb.toString();
		String[] a = s.split(",");

		System.out.println(s);
		System.out.println(a);
	}

	static String concatPath(String folder, String file) {
		if(!folder.endsWith("\\")){
			folder += "\\";
		}

		return folder + file;
	}
}
