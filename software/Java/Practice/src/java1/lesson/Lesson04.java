package lesson;

public class Lesson04 {
	public static void main(String[] args) {
		Body taro = new Body(1.7, 70);
		System.out.println("taro's BMI is " + taro.getBmi());
		taro.setHightAsCm(180);
		System.out.println("taro's height is " + taro.getHeight());
		Body taro2 = new Body();
		System.out.println(taro2.getHeight() + taro2.getWeight());
	}
}
