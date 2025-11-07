class Solution {
    public int maxArea(int[] height) {
        int start = 0, end = height.length-1; 
        int answer = 0; 
        while(start < end){
            int barheight = Math.min(height[start], height[end]); 
            int width = end - start; 
            answer = Math.max(answer, width * barheight); 
            if(height[start] > height[end]){
                end--; 
            } else if(height[start] < height[end]){
                start++; 
            } else{
                start++;
                end--; 
            }
        }

        return answer; 
    }
}