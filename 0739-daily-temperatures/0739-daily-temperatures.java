class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Stack<int[]> stack = new Stack<>(); 
        int[] answer = new int[temperatures.length]; 
        for(int i = 0; i < temperatures.length; i++){
            while(!stack.isEmpty() && stack.peek()[0] < temperatures[i]){
                int index = stack.peek()[1]; 
                answer[index] = i - index; 
                stack.pop(); 
            }
            stack.push(new int[]{temperatures[i],i}); 
        }
        return answer; 
    }
}