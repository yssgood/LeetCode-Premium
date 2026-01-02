class Solution {
    public String longestPalindrome(String s) {
        String answer = String.valueOf(s.charAt(0)); 
        boolean[][] dp = new boolean[s.length()][s.length()]; 
        for(int i = 0; i < s.length(); i++){
            dp[i][i] = true; 
        }
        for(int i = 0; i < s.length()-1; i++){
            if(s.charAt(i) == s.charAt(i+1)){
                dp[i][i+1] = true; 
                answer = s.substring(i,i+2); 
            }
        }

        for(int len = 2; len <= s.length(); len++){
            for(int i = 0; i < s.length() - len; i++){
                int j = i + len; 
                if(s.charAt(i) == s.charAt(j)){
                    if(dp[i+1][j-1] == true){
                        dp[i][j] = true; 
                        answer = s.substring(i,j+1); 
                    }
                }
            }
        }

        return answer; 
    }
}