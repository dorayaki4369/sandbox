package section1;

import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;

//eval()はJavaScriptにあってJavaにはないので、JavaScriptを起動する
public class Q02 {
	public static void main(String[] args) throws ScriptException {
		ScriptEngineManager manager = new ScriptEngineManager();
		ScriptEngine engine = manager.getEngineByName("js");

		String[] op = { "*", "" };
		for (int i = 1000; i < 10000; i++) {
			if (i % 10 != 0) {
				String c = String.valueOf(i);

				for (int j = 0; j < op.length; j++) {
					for (int k = 0; k < op.length; k++) {
						for (int l = 0; l < op.length; l++) {
							String val = c.charAt(3) + op[j] + c.charAt(2) + op[k] + c.charAt(1) + op[l] + c.charAt(0);

							if (val.length() > 4) {
								if (c.equals(engine.eval(val).toString())) {
									System.out.println(val + " = " + i);
								}
							}
						}
					}
				}
			}
		}
	}
}
