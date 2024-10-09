class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0; 
        int start = 0; 
        int end = height.size()-1; 
        while(start < end){
            int width = end - start; 
            int heights = min(height[start], height[end]); 
            answer = max(answer, width * heights); 
            if(height[start] < height[end]){
                start++; 
            } else{
                end--; 
            }
        }

        return answer; 
    }
};