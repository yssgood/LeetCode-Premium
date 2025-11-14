class Solution {
    int index = 0;
    
    public int calculate(String s) {
        return eval(s);
    }
    
    private int eval(String s) {
        Stack<Integer> stack = new Stack<>();
        int num = 0;
        char operator = '+';
        
        while (index < s.length()) {
            char c = s.charAt(index++);
            
            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            }
            
            if (c == '(') {
                num = eval(s);
            }
            
            if ((!Character.isDigit(c) && c != ' ') || index == s.length()) {
                if (operator == '+') {
                    stack.push(num);
                } else if (operator == '-') {
                    stack.push(-num);
                } else if (operator == '*') {
                    stack.push(stack.pop() * num);
                } else if (operator == '/') {
                    stack.push(stack.pop() / num);
                }
                
                if (c == ')') {
                    break;
                }
                
                operator = c;
                num = 0;
            }
        }
        
        int result = 0;
        while (!stack.isEmpty()) {
            result += stack.pop();
        }
        return result;
    }
}