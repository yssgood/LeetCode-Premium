class Solution {
    public String minRemoveToMakeValid(String s) {
        Deque<Integer> stack = new ArrayDeque<>(); 
        Set<Integer> removed = new HashSet<>(); 

        for(int i = 0; i < s.length(); i++){
            char curr = s.charAt(i); 
            if(curr == '('){
                stack.add(i); 
            } else if(curr == ')'){
                if(stack.isEmpty()){
                    removed.add(i); 
                } else{
                    stack.pop(); 
                }
            }
        }
        
        while(!stack.isEmpty()){
            removed.add(stack.pop()); 
        }

        StringBuilder sb = new StringBuilder(); 

        for(int i = 0; i < s.length(); i++){
            if(!removed.contains(i)){
                sb.append(s.charAt(i)); 
            }
        }

        return sb.toString(); 
    }
}