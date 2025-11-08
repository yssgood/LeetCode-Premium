class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> hashSet = new HashSet<>(); 
        for(String next : wordDict) hashSet.add(next); 
        int n = s.length(); 
        boolean[] dp = new boolean[n+1]; 
        dp[0] = true; 
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                String tmp = s.substring(j,i); 
                if(dp[j] == true && hashSet.contains(tmp)){
                    dp[i] = true; 
                }
            }
        }
        return dp[n]; 
    }
}