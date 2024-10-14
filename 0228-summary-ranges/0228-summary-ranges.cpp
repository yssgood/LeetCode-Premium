class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) return {}; 
        vector<string> answer; 
        int curr = nums[0]; 
        int start = 0; 
        for(int i = 1; i < nums.size(); i++){
            int next = curr + 1; 
            if(nums[i] != next){
                string first = to_string(nums[start]); 
                string second = to_string(curr); 
                if(i - start > 1){
                    answer.push_back(first + "->" + second); 
                }  else{
                    answer.push_back(second); 
                }
                start = i; 
            }
            curr = nums[i]; 
        }
        int n = nums.size()-1; 
        string first = to_string(nums[start]); 
        string second = to_string(curr); 
        if(n - start >= 1){
            answer.push_back(first + "->" + second); 
        } else{
            answer.push_back(second); 
        }
        return answer; 
    }
};