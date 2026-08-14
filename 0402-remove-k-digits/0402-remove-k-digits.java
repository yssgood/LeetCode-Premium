class Solution {
    public String removeKdigits(String num, int k) {
        Deque<Character> stack = new ArrayDeque<>(); 
        for(char c : num.toCharArray()){
            while(!stack.isEmpty() && c < stack.peek() && k > 0){
                stack.pop(); 
                k--; 
            } 
            stack.push(c); 

        }

        while(k > 0){
            stack.pop();
            k--; 
        }

        StringBuilder sb = new StringBuilder(); 
        while(!stack.isEmpty()){
            sb.append(stack.pop()); 
        }

        int index = 0; 

        if(!sb.isEmpty()){
            sb.reverse(); 
            while(index < sb.length() && sb.charAt(index) == '0') index++; 
        }

        //System.out.print(index); 

        return index >= sb.length() ? "0" : sb.substring(index); 
    }
}