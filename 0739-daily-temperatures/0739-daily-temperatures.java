class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Deque<int[]> stack = new ArrayDeque<>(); 
        int[] answer = new int[temperatures.length]; 
        
        for(int i = 0; i < temperatures.length; i++){
            int curr = temperatures[i]; 
            if(!stack.isEmpty()){
                while(!stack.isEmpty() && curr > stack.peek()[1]){
                    answer[stack.peek()[0]] = i - stack.peek()[0]; 
                    stack.pop(); 
                }
            }
            stack.push(new int[]{i, curr});
        }
        return answer; 
    }
}