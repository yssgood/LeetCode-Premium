class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer; 
        for(int i = 0; i < nums.size(); i++){
            int start = nums[i]; 
            while(i < nums.size()-1 && nums[i] + 1 == nums[i+1]){
                i++; 
            }

            if(start != nums[i]){
                answer.push_back(to_string(start) + "->" + to_string(nums[i])); 
            } else{
                answer.push_back(to_string(start)); 
            }
        }
        return answer; 
    }
};