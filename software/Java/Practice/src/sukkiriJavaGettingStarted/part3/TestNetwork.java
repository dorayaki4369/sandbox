package part3;

import java.io.InputStream;
import java.net.URL;

public class TestNetwork {
	public static void main(String[] args) throws Exception{
		URL url = new URL("http://www.impressjapan.jp/");
		InputStream iStream = url.openStream();
		int i = iStream.read();
		while (i != -1) {
			char c = (char) i;
			System.out.println(c);
			i = iStream.read();
		}
	}
}
