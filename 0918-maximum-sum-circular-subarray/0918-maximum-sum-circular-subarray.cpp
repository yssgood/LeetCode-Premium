class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxSum = nums[0], currMax = 0;
        int minSum = nums[0], currMin = 0;
        
        for (int num : nums) {
            total += num;
            
            // Kadane for maximum subarray
            currMax = max(currMax + num, num);
            maxSum = max(maxSum, currMax);
            
            // Kadane for minimum subarray
            currMin = min(currMin + num, num);
            minSum = min(minSum, currMin);
        }
        
        // If all negative, return maxSum
        if (maxSum < 0) return maxSum;
        
        // Otherwise, max of (normal, circular)
        return max(maxSum, total - minSum);
    }
};