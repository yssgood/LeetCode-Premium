class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack<>(); 
        for(int n : asteroids){
            
            if(!stack.isEmpty() && stack.peek() > 0 &&  n < 0){ //collide condition 
                int tmp = Math.abs(n); 

                while(!stack.isEmpty()&& stack.peek() < tmp && stack.peek() > 0){ //collide until smaller prev 
                    stack.pop(); 
                }

                if(!stack.isEmpty() && stack.peek() > tmp) continue; //we do nothing 
                if(!stack.isEmpty() && stack.peek() == tmp){ //just pop the equal prev and continue 
                    stack.pop(); 
                    continue; 
                }

                stack.push(n); 


            } else{ //non-collide condition 
                stack.push(n);
            }
        }


        List<Integer> answer = new ArrayList<>(); 
        while(!stack.isEmpty()){
            answer.add(stack.pop()); 
        }
        Collections.reverse(answer); 
        return answer.stream().mapToInt(i->i).toArray(); 
    }
}