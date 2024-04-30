class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size()-1; 
        int answer = INT_MIN; 

        while(start < end){
            int x = end  - start; 
            int y = min(height[start], height[end]); 

            int curr_area = x * y; 
            answer = max(answer, curr_area); 

            if(height[start] < height[end]){
                start++; 
            } else if(height[start] > height[end]){
                end--; 
            } else{
                start++; 
                end--; 
            }
        }

        return answer; 
    }
};