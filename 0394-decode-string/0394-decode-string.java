class Solution {
    public String decodeString(String s) {
        Stack<Integer> numStack = new Stack<>(); 
        Stack<StringBuilder> stringStack = new Stack<>(); 
        int num = 0; 
        StringBuilder sb = new StringBuilder(); 
        for(char c : s.toCharArray()){
            
            if(Character.isDigit(c)){
                num = num * 10 + (c - '0'); 
            } 
            
            if(c == '['){
                numStack.push(num); 
                stringStack.push(sb); 
                num = 0; 
                sb = new StringBuilder();
            } 
            
            if(c == ']'){
                int numTimes = numStack.pop(); 
                StringBuilder tmp = new StringBuilder(); 
                for(int i = 0; i < numTimes; i++){
                    tmp.append(sb.toString()); 
                }
                StringBuilder prev = stringStack.pop(); 
                prev.append(tmp.toString()); 
                sb = prev; 
            } 

            if (Character.isLetter(c)) {
                sb.append(c); 
            }
        }

        return sb.toString(); 
    }
}