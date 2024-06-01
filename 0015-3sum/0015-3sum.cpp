class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer; 
        set<vector<int>> set; 
        sort(nums.begin(), nums.end()); 
        
        for(int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++){
            int start = i + 1;  
            int end = nums.size()-1; 
            while(start < end){
                int res = nums[i] + nums[start] + nums[end];
                if(res == 0){
                    //answer.push_back({nums[i], nums[start], nums[end]}); 
                    set.insert({nums[i], nums[start++], nums[end--]});
                    while(start < end && nums[start] == nums[start-1]) start++; 
                    //start++; 
                    //end--;
                    //break; 
                }

                if(res > 0) end--; 
                if(res < 0) start++; 


            }
        }
        for(auto& it : set){
            answer.push_back(it); 
        }
        return answer; 
    }
};

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(begin(nums), end(nums));
//         vector<vector<int>> res;
//         for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
//             if (i == 0 || nums[i - 1] != nums[i]) {
//                 twoSumII(nums, i, res);
//             }
//         return res;
//     }
//     void twoSumII(vector<int>& nums, int i, vector<vector<int>>& res) {
//         int lo = i + 1, hi = nums.size() - 1;
//         while (lo < hi) {
//             int sum = nums[i] + nums[lo] + nums[hi];
//             if (sum < 0) {
//                 ++lo;
//             } else if (sum > 0) {
//                 --hi;
//             } else {
//                 res.push_back({nums[i], nums[lo++], nums[hi--]});
//                 while (lo < hi && nums[lo] == nums[lo - 1]) ++lo;
//             }
//         }
//     }
// };