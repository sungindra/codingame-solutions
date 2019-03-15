import java.util.*;
import java.io.*;
import java.math.*;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[] numbers = new int[N];
        for (int i = 0; i < N; i++) {
            int pi = in.nextInt();
            numbers[i] = pi;
        }
        Arrays.sort(numbers);
        int minDifference = 0x3f3f3f3f;
        for(int i = 1; i < N; i++) {
            int d = numbers[i] - numbers[i - 1];
            minDifference = Integer.min(minDifference, d);
        }
        System.out.println(minDifference);
    }
}