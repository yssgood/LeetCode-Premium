class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size(); 
        if(n <= 1) return 1; 
        
        map<int,int> dp; 
        int max_ = 1; 
        for(int i = 0; i < n; i++){
            int target = arr[i] - difference; 
            if(dp.count(target)){
                dp[arr[i]] = dp[target] + 1; 
                max_ = max(max_,dp[arr[i]]); 
            } else{
                dp[arr[i]] = 1; 
            }
        }
        return max_; 
    }
};