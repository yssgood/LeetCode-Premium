class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer; 
        sort(nums.begin(), nums.end()); 
        //-4 -1 -1 0 1 2 
        for(int i = 0; i < nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; 
            int start = i + 1, end = nums.size()-1; 
            while(start < end){
                int sum = nums[i] + nums[start] + nums[end]; 

                if(sum > 0){
                    end--; 
                } else if(sum < 0){
                    start++; 
                } else{
                    answer.push_back({nums[i], nums[start], nums[end]}); 
                    while(start + 1 < end && nums[start] == nums[start+1]) start++; 
                    start++; 
                }
            }
        } 
        return answer; 
    }
};