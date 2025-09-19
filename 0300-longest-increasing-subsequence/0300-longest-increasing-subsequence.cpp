class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n,1);
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j]){
                    if (memo[j]+1 > memo[i]){
                        memo[i] = memo[j]+1;
                    }
                }
                //choosing 5 represents + 1 
                //previous doesnt have to be i -1 
            }
        }
        
        int max = -1;
        for (int i = 0; i < n; i++){
            if (memo[i] > max){
                max = memo[i];
            }
        }
        return max;
        
        // memo is a table that have the best value in that specific number 
        // [10,9,2,5] 
        // [1, 1, 1, 1] dp table
        //  i = 5
        //  j 
    }
};