class Solution {
    public int minAddToMakeValid(String s) {
        Stack<Character> stack = new Stack<>(); 
        int lost = 0; 
        for(char c : s.toCharArray()){

            if(c == ')'){
                lost++;
                if(!stack.isEmpty()){
                    lost--;
                    stack.pop(); 
                }
            } else{
                stack.push(c); 
            }
        }

        //ystem.out.print(lost); 

        return stack.size() + lost; 
    }
}

//"()))(("
//))((