class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length(); 
        int[][] dp = new int[n][n]; 
        for(int i = 0; i < n; i++){
            dp[i][i] = 1; 
        }

        int answer = 1; 

        for(int i = n-1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(s.charAt(i) == s.charAt(j)){
                    dp[i][j] = dp[i+1][j-1] + 2; 
                    answer = Math.max(answer,dp[i][j]); 
                } else{
                    dp[i][j] = Math.max(dp[i+1][j], dp[i][j-1]); 
                }
            }
        }

        return answer; 
    }
}