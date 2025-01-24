class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0; 
        int start = 0, end = height.size()-1; 

        while(start < end){
            int currArea = (end - start) * min(height[start], height[end]); 
            answer = max(answer, currArea); 

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