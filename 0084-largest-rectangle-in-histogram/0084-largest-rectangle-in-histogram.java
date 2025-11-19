class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<>(); 
        int answer = 0; 
        int n = heights.length; 
        for(int i = 0; i < heights.length; i++){
            while(!stack.isEmpty () && heights[i] < heights[stack.peek()]){
                int curr = heights[stack.pop()]; 
                int left = stack.isEmpty() ? -1 : stack.peek(); 
                int right = i; 

                int width = (right - left) - 1;  
                answer = Math.max(answer, width * curr); 
            }

            stack.push(i); 
        }

        while(!stack.isEmpty()){
            int curr = heights[stack.pop()]; 
            int left = stack.isEmpty() ? -1 : stack.peek(); 
            int right = n; 

            int width = (right - left) - 1;  
            answer = Math.max(answer, width * curr); 
        }


        return answer; 
    }
}