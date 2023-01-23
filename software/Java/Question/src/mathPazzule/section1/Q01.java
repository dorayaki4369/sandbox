package section1;

//16進数を含めるとものすごく長くなる
public class Q01 {
	public static void main(String[] args) {
		for (int dec = 11;; dec += 2) {
			String bin = Integer.toBinaryString(dec);
			String oct = Integer.toOctalString(dec);
			//String hex = Integer.toHexString(dec);
			String rDec = new StringBuffer(String.valueOf(dec)).reverse().toString();
			String rBin = new StringBuffer(bin).reverse().toString();
			String rOct = new StringBuffer(oct).reverse().toString();
			//String rHex = new StringBuffer(hex).reverse().toString();

			System.out.println(bin + " " + oct + " " + dec /* + " " + hex */);
			if (String.valueOf(dec).equals(rDec) && bin.equals(rBin) && oct.equals(rOct)/* && hex.equals(rHex) */) {
				break;
			}
		}
	}
}
