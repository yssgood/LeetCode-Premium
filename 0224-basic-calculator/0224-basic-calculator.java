class Solution {
    public int calculate(String s) {
        Stack<Integer> stack = new Stack<>(); 
        int sign = 1;  
        int num = 0; 
        int cumulative = 0; 
        for(int i = 0; i < s.length(); i++){
            char curr = s.charAt(i); 
            if(Character.isDigit(curr)){
                num = num * 10 + (curr - '0'); 
            }
            if(curr == '('){
                stack.push(cumulative); 
                stack.push(sign); 
                sign = 1; 
                cumulative = 0; 
            }
            if(curr == ')'){
                cumulative += sign * num; 
                int prevSign = stack.pop(); 
                int prevCumulative = stack.pop(); 
                cumulative *= prevSign;
                cumulative += prevCumulative; 
                num = 0; 
            } else{
                if(curr == '-'){
                    int tmp = num * sign; 
                    cumulative += tmp; 
                    sign = -1; 
                    num = 0; 
                } else if(curr == '+'){
                    int tmp = num * sign; 
                    cumulative += tmp; 
                    sign = 1; 
                    num = 0; 
                }
            }
        }

        cumulative += sign * num; 

        return cumulative; 
    }
}