class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, end = 0; 
        int curr = 0; 
        int answer = INT_MAX; 
        while(end < nums.size()){
            curr += nums[end]; 
            while(curr >= target){
                answer = min(answer, end - start + 1); 
                curr -= nums[start]; 
                start++;  
            }

            // if(curr == target){
            //     //cout << end << ' ' << start << endl; 
            //     answer = min(answer, end - start + 1); 
            // }
            end++; 
        }
        return answer == INT_MAX ? 0 : answer; 
    }
};