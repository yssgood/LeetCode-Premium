class Solution {
    public String decodeString(String s) {
        Stack<Integer> numStack = new Stack<>();
        Stack<StringBuilder> stringStack = new Stack<>(); 
        StringBuilder curr = new StringBuilder(); 
        int num = 0; 
        for(char c : s.toCharArray()){
            if(Character.isDigit(c)){
                num = num * 10 + (c - '0'); 
            } else if(c == '['){
                numStack.push(num); 
                stringStack.push(curr); 
                curr = new StringBuilder(); 
                num = 0; 
            } else if(c == ']'){
                int numTimes = numStack.pop(); 
                StringBuilder tmp = new StringBuilder(); 
                for(int i = 0; i < numTimes; i++){
                    tmp.append(curr.toString()); 
                }
                StringBuilder prev = stringStack.pop(); 
                prev.append(tmp); 
                curr = prev; 
                //stringStack.push(curr); 

            } else{
                curr.append(c); 
            }
        }

        return curr.toString(); 
    }
}