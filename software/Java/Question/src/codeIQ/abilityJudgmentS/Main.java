package codeIQ.abilityJudgmentS;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;

/**
 * Created by dorayaki4369 on 2017/07/07.
 */
public class Main {
    public static void main(String[] args) {
        Scanner scannar = new Scanner(System.in);
        List<Integer[]> matrix = new ArrayList<>();

        while (scannar.hasNext()) {
            String[] num = scannar.nextLine().split("");
            Integer[] array = Stream.of(num).mapToInt(Integer::parseInt).boxed().toArray(Integer[]::new);
            matrix.add(array);
        }

        for (Integer[] list : matrix) {
            for (Integer i : list) {
                System.out.print(i);
            }
            System.out.println();
        }
    }
}
