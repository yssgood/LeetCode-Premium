class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer; 
        sort(nums.begin(), nums.end()); 
        
        for(int i = 0; i < nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; 
            int curr = nums[i]; 
            int start = i + 1; 
            int end = nums.size()-1; 
            while(start < end){
                int second = nums[start]; 
                int third = nums[end];  

                if(curr + second + third > 0){
                    end--; 
                } else if(curr + second + third < 0){
                    start++; 
                } else if(curr + second + third == 0){
                    while(start < end && nums[start] == nums[start+1]) start++; 
                    answer.push_back({curr,second,third}); 
                }

                start++;
                end--; 
            }
        }

        return answer; 
    }
};