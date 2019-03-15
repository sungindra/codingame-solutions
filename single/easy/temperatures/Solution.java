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
        int minDiff = Integer.MAX_VALUE;
        int highest = Integer.MIN_VALUE;
        
        int n = in.nextInt(); // the number of temperatures to analyse
        for (int i = 0; i < n; i++) {
            int t = in.nextInt(); // a temperature expressed as an integer ranging from -273 to 5526
            int diff = Math.abs(t - 0);
            minDiff = Integer.min(minDiff, diff);
            highest = Integer.max(highest, t);
        }
        
        if(highest < 0 && minDiff != Integer.MAX_VALUE) minDiff *= -1;

        // Write an action using System.out.println()
        // To debug: System.err.println("Debug messages...");

        System.out.println(minDiff == Integer.MAX_VALUE? 0: minDiff);
    }
}