class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size()-1; 
        int answer = 0; 
        while(start < end){
            int width = end - start; 
            answer = max(answer, min(height[start], height[end]) * width); 
            if(height[start] < height[end]){
                start++; 
            } else{
                end--; 
            }
        }
        return answer; 
    }
};