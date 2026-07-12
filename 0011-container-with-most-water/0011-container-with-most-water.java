class Solution {
    public int maxArea(int[] height) {
        int left = 0, right = height.length-1; 
        int answer = 0;
        while(left < right){

            int width = right - left; 
            answer = Math.max(answer, width * Math.min(height[left], height[right])); 

            if(height[left] > height[right]){
                right--; 
            } else{
                left++; 
            }
        }

        return answer; 
    }
}