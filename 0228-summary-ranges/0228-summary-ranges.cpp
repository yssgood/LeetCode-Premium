class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer; 
        int n = nums.size(); 
        for(int i = 0; i < n; i++){
            int curr = nums[i]; 
            int next = nums[i]; 
            while(i < n -1 && nums[i+1] == (nums[i] + 1)){
                next = nums[i+1];
                i++;
            }

            if(curr != next){
                answer.push_back(to_string(curr) + "->" + to_string(next)); 
            } else{
                answer.push_back(to_string(curr));  
            }
        }
        return answer; 
    }
};