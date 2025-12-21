class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer; 
        sort(nums.begin(), nums.end()); 
        for(int i = 0; i < nums.size()-2; i++){
            int curr = nums[i]; 
            if(i > 0 && curr == nums[i-1]) continue; 
            int start = i + 1, end = nums.size()-1; 
            while(start < end){
                int second = nums[start];
                int third = nums[end]; 

                int sum = (curr + second + third); 

                if(sum > 0){
                    end--; 
                } else if(sum < 0){
                    start++; 
                } else{
                    answer.push_back({curr, second, third}); 
                    while(start < end && nums[start] == nums[start+1]) start++; 
                    while(start < end && nums[end] == nums[end-1]) end--; 
                    start++;
                    end--; 
                }
            }
        }
        return answer; 
    }
};

//-4 -1 -1 0 1 2 