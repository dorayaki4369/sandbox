package section1;

public class Q5_1 {
    private static int COUNT = 0;

    public static void main(String[] args) {
        for (int coin500 = 0; coin500 <= 2; coin500++) {
            for (int coin100 = 0; coin100 <= 10; coin100++) {
                for (int coin50 = 0; coin50 <= 15; coin50++) {
                    for (int coin10 = 0; coin10 <= 15; coin10++) {
                        if (coin500 + coin100 + coin50 + coin10 <= 15) {
                            if (coin500 * 500 + coin100 * 100 + coin50 * 50 + coin10 * 10 == 1000) {
                                COUNT++;
                            }
                        }

                    }

                }
            }
        }
        System.out.println(COUNT);
    }
}
