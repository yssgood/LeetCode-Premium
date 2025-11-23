class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character> stack = new Stack<>(); 
        for(int i = 0; i < num.length(); i++){
            
            while(!stack.isEmpty() && k > 0 && num.charAt(i) < stack.peek()){
                stack.pop(); 
                k--; 
            }

            stack.push(num.charAt(i)); 
        }

        while(k > 0){
            stack.pop(); 
            k--; 
        }

        StringBuilder sb = new StringBuilder(); 
        while(!stack.isEmpty()){
            sb.append(stack.pop()); 
        }

        sb.reverse(); 
        for(int i = 0; i < sb.length(); i++){
            if(sb.charAt(i) == '0'){
                sb.deleteCharAt(i); 
                i--; 
            } else{
                break; 
            }
        }

        return sb.length() <= 0 ? "0" : sb.toString(); 
    }
}