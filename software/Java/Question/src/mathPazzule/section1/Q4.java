package section1;

public class Q4 {
    public static void main(String[] args) {
        System.out.println(cutBar(3, 20));
        System.out.println(cutBar(5, 100));
    }

    public static int cutBar(int m, int n) {
        int count = 0;
        int current = 1;

        while (n > current) {
            current += current < m ? current : m;
            count++;
        }
        return count;
    }
}
