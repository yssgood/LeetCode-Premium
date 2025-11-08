class Solution {
    public String longestPalindrome(String s) {
        if(s.length() <= 1) return s; 
        
        int n = s.length(); 
        boolean[][] dp = new boolean[n][n]; 

        for(int i = 0; i < n; i++){
            dp[i][i] = true; 
        }

        int left = 0; 
        int right = 0; 

        for(int i = 0; i < n - 1; i++){
            if(s.charAt(i) == s.charAt(i+1)){
                left = i; 
                right = i + 1; 
                dp[i][i+1] = true; 
            }
        }


        for(int len = 3; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = i + len - 1; 
                if(s.charAt(i) == s.charAt(j) && dp[i+1][j-1]){
                    dp[i][j] = true; 
                    left = i;
                    right = j; 
                }
            }
        }

        return s.substring(left,right+1); 
    }
}