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
        String message = in.nextLine();
        
        String binary = "";
        for(int i = 0; i < message.length(); i++) {
            char current = message.charAt(i);
            int temp = Integer.parseInt(Integer.toBinaryString(current));
            binary += String.format("%07d", temp);
        }

        String answer = "";
        
        char[] bits = binary.toCharArray();
        char current = ' ';
        for(int idx = 0; idx < bits.length; idx++) {
            char b = bits[idx];
            if(b != current) {
                //put into answer
                if(idx > 0) {
                    if(b == '1') answer += " 0";
                    else answer += " 00";
                } else {
                    answer += ((b == '1')? "0": "00");
                }

                //reset
                current = b;
                answer += " 0";
            } else {
                answer += "0";
            }
        }
        answer += " ";
        
        System.out.println(answer.trim());
    }
}