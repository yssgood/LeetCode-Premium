class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double answer = INT_MIN; 
        int start = 0, end = 0; 
        double curr_sum = 0; 
        while(end < nums.size()){
            curr_sum += nums[end]; 
            if((end - start) + 1 == k){
                answer = max(answer, curr_sum / k); 
                curr_sum -= (nums[start]); 
                start++; 
            }

            end++; 
        }

        return answer;         
    }
};