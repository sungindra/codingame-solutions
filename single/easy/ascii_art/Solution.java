import java.util.*;
import java.io.*;
import java.math.*;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class Solution {
    
    static char[][] arena;
    static int L;
    static int H;
    
    public static void print(final char[] T) {
        for(int i = 0; i < H; i++) { //row
            for(int j = 0; j < T.length; j++) {
                int start = ('A' <= T[j] && T[j] <= 'Z')? (int)(T[j] - 'A') * L: 26 * L;
                for(int k = 0; k < L; k++) {
                    System.out.print(arena[i][start + k]);
                }
                
            }
            System.out.println();
        }
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        L = in.nextInt();
        H = in.nextInt();
        in.nextLine();
        
        char[] T = in.nextLine().toUpperCase().toCharArray();
        
        arena = new char[H][L*27];
        
        for (int i = 0; i < H; i++) {
            char[] row = in.nextLine().toCharArray();
            System.arraycopy(row, 0, arena[i], 0, row.length);
            
        }
        
        print(T);
    }
}