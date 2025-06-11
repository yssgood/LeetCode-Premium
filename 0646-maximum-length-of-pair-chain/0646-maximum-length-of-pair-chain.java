class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, (a,b) -> a[0] - b[0]); 
        int n = pairs.length; 
        if(n <= 1) return 1; 

        int[] dp = new int[n]; 
        Arrays.fill(dp,1); 

        for(int i = 1; i < n; i++){
            int c = pairs[i][0]; 
            for(int j = 0; j < i; j++){
                int b = pairs[j][1]; 
                if(b < c){
                    dp[i] = Math.max(dp[i], dp[j] + 1); 
                }
            }
        }
        return dp[n-1]; 
    }
}