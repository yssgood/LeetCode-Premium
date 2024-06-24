class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        // Queue to keep track of flips
        deque<int> flipQueue;
        // Current flip state
        int flipped = 0;
        // Total number of flips
        int result = 0;

        for (int i = 0; i < n; ++i) {
            // Remove the effect of the oldest flip if it's out of the current
            // window
            if (i >= k) {
                flipped ^= flipQueue.front();
                flipQueue.pop_front();
            }

            // If the current bit is 0 it needs to be flipped
            if (flipped == nums[i]) {
                // If we cannot flip a subarray starting at index i
                if (i + k > n) {
                    return -1;
                }
                // Add a flip at this position
                flipQueue.push_back(1);
                // Toggle the flipped state
                flipped ^= 1;
                // Increment the flip count
                result += 1;
            } else {
                flipQueue.push_back(0);
            }
        }

        return result;
    }
};