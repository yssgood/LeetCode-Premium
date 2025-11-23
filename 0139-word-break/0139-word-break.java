class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[] dp = new boolean[s.length()+1]; 
        Set<String> set = new HashSet<>(); 
        for(String ss : wordDict) set.add(ss); 
        dp[0] = true; 
        for(int i = 1; i <= s.length(); i++){
            for(int j = 0; j < i; j++){
                String tmp = s.substring(j,i); 
                if(set.contains(tmp) && dp[j] == true){
                    dp[i] = true;  
                }
            }
        }

        return dp[s.length()]; 
    }
}