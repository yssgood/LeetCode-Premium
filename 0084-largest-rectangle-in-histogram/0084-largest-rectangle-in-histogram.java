class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> indexStack = new Stack<>(); 
        int max_ = 0;
        for(int i = 0; i < heights.length; i++){
            int currWeight = heights[i]; 

            while(!indexStack.isEmpty() && currWeight < heights[indexStack.peek()]){
                int currIndex = indexStack.pop(); 
                int left = (indexStack.isEmpty()) ? -1 : indexStack.peek(); 
                int right = i; 
                int width = (right - left) - 1; 
                max_ = Math.max(max_, width * heights[currIndex]);
            }

            indexStack.push(i); 
        }

        while(!indexStack.isEmpty()){
            int curr = heights[indexStack.pop()]; 
            int left = indexStack.isEmpty() ? -1 : indexStack.peek(); 
            int right = heights.length; 

            int width = (right - left) - 1; 
            max_ = Math.max(max_, width * curr);
        }
        return max_; 
    }
}