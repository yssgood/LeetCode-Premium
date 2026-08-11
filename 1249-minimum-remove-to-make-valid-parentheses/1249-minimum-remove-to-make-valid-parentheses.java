class Solution {
    public String minRemoveToMakeValid(String s) {
        Deque<Integer> stack = new ArrayDeque<>(); 
        StringBuilder sb = new StringBuilder(s); 
        for(int i = 0; i < s.length(); i++){
            char curr = sb.charAt(i); 
            if(curr == ')'){
                if(!stack.isEmpty()){
                    stack.pop(); 
                } else{
                    sb.setCharAt(i,'?'); 
                }
            }
            if(curr == '('){
                stack.push(i); 
            }
        }

        while(!stack.isEmpty()){
            sb.setCharAt(stack.pop(),'?'); 
        }

        for(int i = sb.length() - 1; i >= 0; i--){
            if(sb.charAt(i) == '?') sb.deleteCharAt(i); 
        }

        

        return sb.toString(); 
    }
}