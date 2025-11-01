class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>(); 
        Map<Character,Character> hashMap = Map.of('(',')', '[', ']', '{', '}'); 

        for(char c : s.toCharArray()){
            if(hashMap.containsKey(c)){
                stack.push(c); 
            } else{
                if(stack.isEmpty()) return false; 

                char top = stack.peek(); 
                if(c == hashMap.get(top)){
                    stack.pop(); 
                } else {
                    return false; 
                }
            }
        }


        return stack.isEmpty(); 
    }
}