class Solution {
    public List<Integer> diffWaysToCompute(String expression) {
        List<Integer> answer = new ArrayList<>(); 

        for(int i = 0; i < expression.length(); i++){
            char curr = expression.charAt(i); 
            if(curr == '-' || curr == '+' || curr == '*'){
                List<Integer> left = diffWaysToCompute(expression.substring(0,i)); 
                List<Integer> right = diffWaysToCompute(expression.substring(i+1)); 

                //left = 2 
                //right = [-17,-5] 
                //mainStack : [-34, -10] 


                for(int l : left){
                    for(int r : right){
                        if(curr == '-'){
                            answer.add(l - r); 
                        } else if(curr == '+'){
                            answer.add(l + r); 
                        } else{
                            answer.add(l * r); 
                        }
                    }
                }

            }
        }

        if(answer.isEmpty()){
            answer.add(Integer.parseInt(expression)); 
        }

        return answer; 
    }
}