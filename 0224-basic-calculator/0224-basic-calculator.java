class Solution {
    public int calculate(String s) {
        int sign = 1; 
        int num = 0; 
        int result = 0; 
        Stack<Integer> stack = new Stack<>(); 

        for(char c : s.toCharArray()){
            if(Character.isDigit(c)){
                num = num * 10 + (c - '0'); 
            }

            if(c == '('){
                stack.push(result);
                stack.push(sign); 
                result = 0; 
                num = 0; 
                sign = 1; 
            } else if(c == ')'){
                result += sign * num; 
                num = 0; 
                int prevSign = stack.pop(); 
                int prevResult = stack.pop(); 

                result = prevResult + prevSign * result; 


            } else if (!Character.isDigit(c) && c != ' '){
                result += sign * num; 
                num = 0; 
                sign = (c == '+') ? 1 : -1; 
            }
        }

        if(num != 0){
            result += sign * num; 
        }

        return result; 
    }
}