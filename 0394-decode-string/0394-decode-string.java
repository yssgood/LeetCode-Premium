class Solution {
    public String decodeString(String s) {
        Stack<String> stack = new Stack<>(); 
        Stack<Integer> numStack = new Stack<>(); 
        int num = 0; 
        StringBuilder sb = new StringBuilder(); 
        for(char c : s.toCharArray()){
            if(Character.isDigit(c)){
                num = num * 10 + (c - '0');
            } else if(c == '['){
                numStack.push(num); 
                stack.push(sb.toString()); 
                num = 0; 
                sb = new StringBuilder(); 
            } else if(c == ']'){
                int numTimes = numStack.pop(); 
                StringBuilder tmp = new StringBuilder(); 
                for(int i = 0; i < numTimes; i++){
                    tmp.append(sb.toString()); 
                }
                String prev = stack.pop(); 
                StringBuilder newString = new StringBuilder(); 
                newString.append(prev).append(tmp); 
                sb = newString; 
                
            } else{
                sb.append(c); 
            }
        }

        return sb.toString(); 
    }
}