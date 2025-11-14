class Solution {
    public int calculate(String s) {
        int result = 0; 
        int num = 0; 
        char operator = '+'; 
        Stack<Integer> stack = new Stack<>(); 
        for(char c : s.toCharArray()){
            if(Character.isDigit(c)){
                num = num * 10 + (c -'0'); 
            } 

            if (!Character.isDigit(c) && c != ' '){
                if(operator == '+'){
                    result = result + num; 
                    if(c == '+' || c== '-') operator = c; 
                    num = 0; 
                }
                if(operator == '-'){
                    result = result + (-num); 
                    if(c == '+' || c== '-') operator = c; 
                    num = 0; 
                }
                if(c == '('){
                    stack.push(result); 
                    if(operator == '+') stack.push(1); 
                    if(operator == '-') stack.push(-1); 

                    operator = '+';
                    num = 0; 
                    result = 0; 
                } 
                if(c == ')'){
                    if(operator == '+') result = result + num; 
                    if(operator == '-') result = result + (-num); 
                    // System.out.print(result + " "); 
                    // System.out.println(num); 
                    result *= stack.pop(); 
                    result += stack.pop(); 

                    operator = '+'; 
                    num = 0; 
                }
            }
        }

        if(operator == '+') result += num; 
        if(operator == '-') result += num; 

        return result; 
    }
}