class Solution {
public:
//[-4,-1,-1,0,1,2,] 
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer; 
        sort(nums.begin(), nums.end()); 
        for(int i = 0; i < nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; 
            int curr = nums[i]; 
            int start = i + 1, end = nums.size()-1; 
            while(start < end){
                int sum = curr + nums[start] + nums[end]; 

                if(sum == 0){
                    answer.push_back({curr,nums[start],nums[end]}); 
                    start++; 
                    while(start < end && nums[start] == nums[start-1]) start++; 
                } else if(sum < 0){
                    start++; 
                } else{
                    end--; 
                }

            }
        }
        return answer; 
    }
};