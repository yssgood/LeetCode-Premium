class Solution {
private:
    int solve(int i, unordered_map<int,int>& hashMap, vector<int>& memo) {
        // Base cases
        if (i == 0) return 0;
        if (i == 1) return hashMap[1];
        
        // Check memo
        if (memo[i] != -1) return memo[i];
        
        // Same recurrence: max(dp[i-1], dp[i-2] + hashMap[i])
        int notChoose = solve(i-1,hashMap,memo); 
        int choose = solve(i-2,hashMap,memo) + hashMap[i]; 
        memo[i] = max(choose, notChoose);
        return memo[i];
    }
    
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        unordered_map<int,int> hashMap; 
        int max_ = *max_element(nums.begin(), nums.end());
        for(int n : nums) hashMap[n] += n; 
        vector<int> memo(max_ + 1, -1); 
        
        return solve(max_, hashMap, memo);
    }
};