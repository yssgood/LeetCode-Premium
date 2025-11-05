class Solution {
    public int calculate(String s) {
        Stack<Integer> numStack = new Stack<>(); 
        int num = 0; 
        char op = '+'; 
        int answer = 0; 
        for(int i = 0; i < s.length(); i++){
            char currChar = s.charAt(i); 
            if(Character.isDigit(currChar)){
                num = num * 10 + (currChar - '0'); 
            }

            if(!Character.isDigit(currChar) && currChar != ' ' || i == s.length()-1){
                if(op == '+'){
                    numStack.push(num); 
                } else if(op == '-'){
                    numStack.push(-num); 
                } else if(op == '*'){
                    numStack.push(numStack.pop() * num); 
                } else{
                    numStack.push(numStack.pop() / num); 
                }
                num = 0; 
                op = currChar; 
            }
        }

        while(!numStack.isEmpty()){
            answer += numStack.pop(); 
        }

        return answer; 
    }
}