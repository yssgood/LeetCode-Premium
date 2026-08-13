class Solution {
    public String minRemoveToMakeValid(String s) {
        Deque<Integer> stack = new ArrayDeque<>(); 
        Set<Integer> banned = new HashSet<>(); 
        for(int i = 0; i < s.length(); i++){
            char curr = s.charAt(i); 
            if(curr == ')'){
                if(!stack.isEmpty()) stack.pop(); 
                else banned.add(i); 
            } else if(curr == '('){
                stack.push(i); 
            }
        }

        while(!stack.isEmpty()){
            banned.add(stack.pop()); 
        }

        String answer = ""; 
        for(int i = 0; i < s.length(); i++){
            if(!banned.contains(i)){
                answer += s.charAt(i); 
            }
        }

        return answer; 
    }
}