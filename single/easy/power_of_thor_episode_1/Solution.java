import java.util.*;
import java.io.*;
import java.math.*;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/
class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int lightX = in.nextInt(); // the X position of the light of power
        int lightY = in.nextInt(); // the Y position of the light of power
        int initialTX = in.nextInt(); // Thor's starting X position
        int initialTY = in.nextInt(); // Thor's starting Y position

        // game loop
        while (true) {
            int remainingTurns = in.nextInt(); // The remaining amount of turns Thor can move. Do not remove this line.

            String move = "";
            if(lightY - initialTY > 0) { //light is at bottom of Thor
                initialTY++;
                move += "S";
            } else if(lightY - initialTY < 0) { //light is above Thor
                initialTY--;
                move += "N";
            }
            
            if(lightX - initialTX > 0) { //light is at right of Thor
                initialTX++;
                move += "E";
            } else if(lightX - initialTX < 0) {
                initialTX--;
                move += "W";
            }
            System.out.println(move);
        }
    }
}