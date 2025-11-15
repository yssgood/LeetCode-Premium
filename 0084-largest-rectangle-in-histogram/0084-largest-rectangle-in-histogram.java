class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<>(); 
        int result = 0; 
        int n = heights.length;

        for (int i = 0; i < n; i++) {

            // 현재 막대가 스택 top보다 낮으면 → pop하며 면적 계산
            while (!stack.isEmpty() && heights[i] < heights[stack.peek()]) {
                int height = heights[stack.pop()];

                int left = stack.isEmpty() ? -1 : stack.peek();
                int right = i;

                int width = right - left - 1;

                result = Math.max(result, height * width);
            }

            stack.push(i); 
        }

        // 남은 것들 처리
        while (!stack.isEmpty()) {
            int height = heights[stack.pop()];

            int left = stack.isEmpty() ? -1 : stack.peek();
            int right = n;

            int width = right - left - 1;

            result = Math.max(result, height * width);
        }

        return result; 
    }
}
