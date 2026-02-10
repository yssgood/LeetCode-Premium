class Solution {
    public String decodeString(String s) {
        Stack<StringBuilder> sbStack = new Stack<>(); 
        Stack<Integer> numStack = new Stack<>(); 
        int num = 0; 
        int index = 0; 
        int n = s.length();
        StringBuilder sb = new StringBuilder(); 
        while(index < n){
            
            if(Character.isDigit(s.charAt(index))){
                num = (num * 10) + s.charAt(index) - '0'; 
            }

            if(Character.isAlphabetic(s.charAt(index))){
                sb.append(s.charAt(index)); 
            }

            if(s.charAt(index) == '['){
                sbStack.push(sb); 
                numStack.push(num); 
                num = 0; 
                sb = new StringBuilder(); 
            } else if(s.charAt(index) == ']'){
                StringBuilder prev = sbStack.pop(); 
                int numTmp = numStack.pop(); 
                for(int i = 0; i < numTmp; i++){
                    prev.append(sb); 
                }
                sb = prev; 
            }

            index++; 
        }

        return sb.toString(); 
    }
}