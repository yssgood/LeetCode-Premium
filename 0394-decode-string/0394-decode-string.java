class Solution {
    public String decodeString(String s) {
        Stack<Character> stack = new Stack<>(); 
        for(char c : s.toCharArray()){
            if(c == ']'){
                //create string 
                StringBuilder tmp = new StringBuilder(); 
                StringBuilder num = new StringBuilder(); 
                StringBuilder res = new StringBuilder(); 
                while(!stack.isEmpty() && !Character.isDigit(stack.peek())){
                    if(Character.isLetter(stack.peek())){
                        tmp.append(stack.peek());
                    }
                    stack.pop(); 
                }

                tmp.reverse(); 
                
                while(!stack.isEmpty() && Character.isDigit(stack.peek())){
                    num.append(stack.peek()); 
                    stack.pop(); 
                }

                num.reverse(); 

                int convert = Integer.parseInt(num.toString()); 
                for(int i = 0; i < convert; i++){
                    res.append(tmp); 
                }
                //System.out.println(res.toString()); 
                //putting it back to stack 
                for(char next : res.toString().toCharArray()){
                    stack.push(next); 
                }
            } else{
                stack.push(c); 
            }
        }
        
        StringBuilder answer = new StringBuilder(); 

        while(!stack.isEmpty()){
            answer.append(stack.peek()); 
            stack.pop(); 
        }

        answer.reverse(); 

        return answer.toString(); 
    }
}





/*

3[a ]
string tmp = "a" 
num = 3 

"aaa" 
2[bc ]

cb 
bc 
num 2 

aaabcbc 



3[a2[c  ] 
tmp = c 
num = 2 

cc

3[acc  ]

cca 
acc 
3 

acc acc acc 


*/ 