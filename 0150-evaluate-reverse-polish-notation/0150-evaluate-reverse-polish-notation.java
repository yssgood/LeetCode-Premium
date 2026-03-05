class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>(); 
        for(String s : tokens){
            if(s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")){
                int num1 = stack.pop(); 
                int num2 = stack.pop(); 

                int result = 0; 
                if(s.equals("+")){
                    result = num1 + num2; 
                } else if(s.equals("-")){
                    result = num2 - num1; 
                } else if(s.equals("*")){
                    result = num1 * num2; 
                } else{
                    result = num2 / num1; 
                }

                //System.out.println(result); 

                stack.add(result); 
                
            } else{
                if(s.charAt(0) ==  '-'){
                    stack.add(Integer.parseInt(s.substring(1)) * -1);  
                } else{
                    stack.add(Integer.parseInt(s)); 
                }
            }
        }

        return stack.pop(); 
    }
}