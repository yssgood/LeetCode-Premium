class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int maxLen = 0; 
        unordered_map<long long, int> hashMap; 
        hashMap[0] = -1;  // Handle subarrays starting from index 0
        
        // Build prefix sums AND store first occurrences in one pass
        for(int i = 1; i < nums.size(); i++){
            nums[i] = nums[i-1] + nums[i]; 
        }
        
        // Store first occurrences (but don't overwrite hashMap[0]!)
        if(nums[0] != 0) {  // Only store if it won't overwrite our base case
            hashMap[nums[0]] = 0;
        }
        for(int i = 1; i < nums.size(); i++){
            if(!hashMap.count(nums[i])) {
                hashMap[nums[i]] = i; 
            }
        }
        
        // Find maximum length
        for(int i = 0; i < nums.size(); i++){
            long long target = (long long)nums[i] - k; 
            if(hashMap.count(target)){
                maxLen = max(maxLen, i - hashMap[target]); 
            }
        }
        return maxLen; 
    }
};