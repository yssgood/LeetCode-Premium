class Solution {
    public String decodeString(String s) {
        Stack<Integer> numStack = new Stack<>(); 
        Stack<StringBuilder> sbStack = new Stack<>(); 
        int num = 0; 
        StringBuilder curr = new StringBuilder(); 

        for(char c : s.toCharArray()){
            if(Character.isDigit(c)){
                num = num * 10 + (c - '0'); 
            } else if(c == '['){
                numStack.push(num); 
                sbStack.push(curr); 
                curr = new StringBuilder(); 
                num = 0; 
            } else if(c == ']'){
                int prevNum = numStack.pop(); 
                curr = new StringBuilder(curr.toString().repeat(prevNum));
                if(!sbStack.isEmpty()){
                    curr = sbStack.pop().append(curr); 
                }
            } else{
                curr.append(c); 
            }
        }



        return curr.toString(); 
    }
}