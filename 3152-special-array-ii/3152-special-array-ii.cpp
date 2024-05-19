class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        //prefix array
        vector<int> store(nums.size(), 0);
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] % 2) != (nums[i - 1] % 2)) {
                store[i] = store[i - 1] + 1;
            } else {
                store[i] = store[i - 1];
            }
        }
        
        vector<bool> ans;
        for ( auto query : queries) {
            int left = query[0];
            int right = query[1];
           // length of special sub array is equal to query length
            if ((store[right] - store[left]) == (right - left)) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};