class Solution {
    public int calculate(String s) {
        int result = 0; 
        int num = 0; 
        int sign = 1; 
        Stack<Integer> numStack = new Stack<>(); 
        for(char c : s.toCharArray()){
            if(Character.isDigit(c)){
                num = num * 10 + (c-'0'); 
            } else{
                if(c == '+'){
                    result += sign * num; 
                    sign = 1; 
                    num = 0;  
                } else if(c == '-'){
                    result += sign * num; 
                    sign = -1; 
                    num = 0; 
                } else if(c == '('){
                    numStack.push(result); 
                    numStack.push(sign); 
                    result = 0; 
                    sign = 1; 
                } else if(c == ')'){
                    result += sign * num; 
                    num = 0;  

                    result *= numStack.pop(); 
                    result += numStack.pop(); 
                }
            }
        }

        result += sign * num; 
        return result; 
    }
}