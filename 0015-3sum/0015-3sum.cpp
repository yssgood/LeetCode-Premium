class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer; 
        sort(nums.begin(), nums.end()); 
        for(int i = 0; i < nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; 
            int curr = nums[i]; 
            int start = i + 1, end = nums.size()-1; 
            while(start < end){
                int second = nums[start]; 
                int third = nums[end];  

                int sum = curr + second + third; 

                if(sum > 0){
                    end--; 
                } else if(sum < 0){
                    start++; 
                } else{
                    while(start < end && nums[start] == nums[start+1]) start++; 
                    while(start < end && nums[end] == nums[end-1]) end--; 
                    answer.push_back({curr,second,third}); 
                    start++;
                    end--; 
                }
            }
        }
        return answer; 
    }
};