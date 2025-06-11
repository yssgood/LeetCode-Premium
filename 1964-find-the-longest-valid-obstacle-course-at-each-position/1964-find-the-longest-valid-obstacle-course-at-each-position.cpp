class Solution {
public:
    // Fixed binary search - now searches in the LIS array, not obstacles
    int binarySearch(vector<int>& dp, int target){
        int left = 0, right = dp.size();
        
        while(left < right){
            int mid = left + (right - left) / 2; 
            
            if(dp[mid] <= target){
                left = mid + 1; 
            } else{
                right = mid; 
            }
        } 
        
        return left; 
    }
    
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size(); 
        if(n <= 1) return {1}; 
        
        vector<int> answer(n);
        vector<int> dp; // This is your "dp" array but now it's the LIS array
        
        for(int i = 0; i < n; i++){  // Start from 0, not 1
            int pos = binarySearch(dp, obstacles[i]); 
            
            if(pos == dp.size()){
                dp.push_back(obstacles[i]);
            } else {
                dp[pos] = obstacles[i];
            }
            
            answer[i] = pos + 1;  // Length is position + 1
        }

        return answer; 
    }
};