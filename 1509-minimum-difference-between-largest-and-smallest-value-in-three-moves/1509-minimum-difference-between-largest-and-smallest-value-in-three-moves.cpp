class Solution {
public:
    int minDifference(vector<int>& nums) {
        int numsSize = nums.size();
        if(nums.size() <= 4) return 0; 
        sort(nums.begin(), nums.end()); 
        int minDiff = INT_MAX; 
        for (int left = 0, right = numsSize - 4; left < 4; left++, right++) {
            minDiff = min(minDiff, nums[right] - nums[left]);
        }

        return minDiff; 
    }
};


//[6,6,0,1,1,4,6]
//[0,0,1,1,4,6,6,6]