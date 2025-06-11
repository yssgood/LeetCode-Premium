class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>(); 
        Map<Character,Character> hashMap = Map.of(')','(',']','[','}','{'); 
        for(char c : s.toCharArray()){
            if(hashMap.containsKey(c)){
                if(stack.isEmpty() || stack.peek() != hashMap.get(c)) return false;
                stack.pop(); 
            } else{
                stack.push(c);
            }
        }

        return stack.isEmpty(); 
    }
}