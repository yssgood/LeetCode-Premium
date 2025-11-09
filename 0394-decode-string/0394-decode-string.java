class Solution {
    public String decodeString(String s) {
        Stack<Integer> numStack = new Stack<>(); 
        Stack<String> stack = new Stack<>(); 
        int num = 0; 
        StringBuilder sb = new StringBuilder(); 
        for(char c : s.toCharArray()){
            if(Character.isDigit(c)){
                num = num * 10 + (c-'0'); 
            } else if(c == '['){
                numStack.push(num); 
                stack.push(sb.toString()); 
                num = 0; 
                sb = new StringBuilder(); 
            } else if(c == ']'){
                int nextDigit = numStack.pop(); 
                StringBuilder tmp = new StringBuilder(stack.pop());
                for(int i = 0; i < nextDigit; i++){
                    tmp.append(sb.toString()); 
                }
                sb = tmp; 
            } else{
                sb.append(c); 
            }
        }

        return sb.toString(); 
    }
}