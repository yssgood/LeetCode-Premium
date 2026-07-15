class Solution {
    public int calculate(String s) {
        Stack<Integer> stack = new Stack<>();
        int result = 0; 
        int sign = 1; 
        int curr = 0; 
        for(char c : s.toCharArray()){
            if(Character.isDigit(c)){
                curr = curr * 10 + (c - '0'); 
            }

            if(c == '+'){
                result += sign * curr; 
                curr = 0; 
                sign = 1; 
            }

            if(c == '-'){
                result += sign * curr; 
                curr = 0; 
                sign = -1; 
            }

            if(c == '('){
                stack.push(result); 
                stack.push(sign); 
                result = 0; 
                sign = 1; 
            }

            if(c == ')'){
                result += sign * curr; 
                curr = 0; 
                result *= stack.pop();
                result += stack.pop();
                sign = 1; 
            }
        }

        return result + sign * curr; 
    }
}