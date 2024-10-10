class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double answer = INT_MIN;  
        double sum = 0; 
        int start = 0, end = 0;
        while(end < nums.size()){
            sum += nums[end];
            while(end - start + 1 >= k){
                answer = max(answer, sum / (end - start + 1));
                sum -= nums[start++];
            }
            end++; 
        }
        return answer; 
    }
};