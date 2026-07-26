class Solution {
    public String decodeString(String s) {
        Stack<StringBuilder> stack = new Stack<>(); 
        Stack<Integer> numStack = new Stack<>(); 

        int num = 0; 
        StringBuilder curr = new StringBuilder(); 

        for(char c : s.toCharArray()){
            if(Character.isDigit(c)){
                num = num * 10 + (c - '0'); 
            } else if(c == '['){
                numStack.push(num); 
                stack.push(curr); 
                num = 0; 
                curr = new StringBuilder(); 
            } else if(c == ']'){
                int numTimes = numStack.pop(); 
                StringBuilder tmp = new StringBuilder();
                for(int i = 0; i < numTimes; i++){
                    tmp.append(curr); 
                }
                StringBuilder prev = stack.pop(); 
                prev.append(tmp); 
                curr = prev; 
            } else{
                curr.append(c); 
            }
        }

        return curr.toString(); 
    }
}