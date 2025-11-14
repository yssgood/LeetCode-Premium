class Solution {
    public int calculate(String s) {
        int result = 0; 
        int num = 0; 
        char operator = '+'; 
        Stack<Integer> charStack = new Stack<>(); 
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i); 
            if(Character.isDigit(c)){
                num = num * 10 + (c - '0'); 
            } 
            
            if(!Character.isDigit(c) && c != ' ' || i == s.length()-1){
                if(operator == '+'){
                    charStack.push(num); 
                    num = 0; 
                    operator = c; 
                } else if(operator == '-'){
                    charStack.push(-num);
                    num = 0; 
                    operator = c; 
                } else if(operator == '*'){
                    //System.out.print("h"); 
                    charStack.push(num * charStack.pop()); 
                    num = 0; 
                    operator = c; 
                } else{
                    charStack.push(charStack.pop() / num); 
                    num = 0; 
                    operator = c; 
                }
            }
        }

        while(!charStack.isEmpty()){
            result += charStack.pop(); 
        }

        return result; 
    }
}