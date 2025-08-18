class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long long, long long> prefixSumMap;  // prefixSum -> first index
        prefixSumMap[0] = -1;  // Handle case where subarray starts from index 0
        
        long long prefixSum = 0;
        long long maxLen = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            
            // If prefixSum - k exists in map, we found a valid subarray
            if (prefixSumMap.count(prefixSum - k)) {
                maxLen = max(maxLen, i - prefixSumMap[prefixSum - k]);
            }
            
            // Only store first occurrence of this prefixSum
            if (!prefixSumMap.count(prefixSum)) {
                prefixSumMap[prefixSum] = i;
            }
        }
        
        return maxLen;
    }
};