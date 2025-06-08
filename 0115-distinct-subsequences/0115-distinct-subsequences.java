class Solution {
    public int numDistinct(String s, String t) {
        int m = s.length(), n = t.length(); 
        int[][] dp = new int[m+1][n+1]; 
        dp[0][0] = 1; 

        for(int i = 1; i <= m; i++){
            dp[i][0] = 1; 
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s.charAt(i-1) == t.charAt(j-1)){
                    //dp[i][j] = dp[i-1][j-1] + 1;
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; 
                } else{
                    //dp[i][j] = dp[i][j-1]; 
                    dp[i][j] = dp[i-1][j]; 
                }
            }
        }

        // for(int i = 0; i <= m; i++){
        //     for(int j = 0; j <= n; j++){
        //         System.out.print(dp[i][j]);
        //         System.out.print(' ');  
        //     }
        //     System.out.println(); 
        // }

        return dp[m][n]; 
    }
}