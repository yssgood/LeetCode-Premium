class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>(); 
        for(String s : tokens){
            int result = 0; 
            if(s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")){
                int right = stack.pop(); 
                int left = stack.pop(); 

                if(s.equals("+")) result = left + right; 
                if(s.equals("-")) result = left - right; 
                if(s.equals("*")) result = left * right; 
                if(s.equals("/")) result = left / right; 
            } else{
                result = Integer.parseInt(s); 
            }

            stack.push(result); 
        }
        return stack.pop(); 
    }
}