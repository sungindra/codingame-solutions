import java.util.*;

class Solution {
    
    final int INFINITY = 0x3f3f3f3f;
    final int MINIMUM = -1 * INFINITY;
    
    int[] prizes;
    int days;
    
    int[][] memo;
    
    int DP(int idx, int daysLeft) {
        if(idx >= prizes.length) return 0;
        
        //no days left
        if(daysLeft <= 0) return DP(idx + 1, days);
        
        //memo here
        if(memo[idx][daysLeft] != -1) return memo[idx][daysLeft];
        
        //take or skip
        int firstOption = DP(idx + 1, daysLeft - 1) + prizes[idx];
        int secondOption = DP(idx + 1, days);
        
        int maxi = Integer.max(firstOption, secondOption);
        memo[idx][daysLeft] = maxi;
        return maxi;
    }
    
    public Solution() {
        Scanner reader = new Scanner(System.in);
        int N = reader.nextInt();
        days = reader.nextInt();
        
        memo = new int[N + 3][days + 3];
        for(int[] m : memo) Arrays.fill(m, -1);
        
        prizes = new int[N];
        for (int i = 0; i < N; i++) prizes[i] = reader.nextInt();
        
        
        System.out.println(DP(0, days));
    }
    
    public static void main(String args[]) {
        new Solution();
    }
}