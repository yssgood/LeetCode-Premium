class Solution {
    Map<String,List<Integer>> memo = new HashMap<>(); 
    public List<Integer> diffWaysToCompute(String expression) {
        return helper(expression); 
    }
    public List<Integer> helper(String expression) {
        if(memo.containsKey(expression)) return memo.get(expression); 
        List<Integer> res = new ArrayList<>(); 
        boolean isNumber = true; 

        for(char c : expression.toCharArray()){
            if(!Character.isDigit(c)){
                isNumber = false;
                break; 
            }
        }

        if(isNumber){
            res.add(Integer.parseInt(expression)); 
            return res; 
        }

        for(int i = 0; i < expression.length(); i++){
            char op = expression.charAt(i); 

            if(!Character.isDigit(op)){
                List<Integer> left = helper(expression.substring(0,i)); 
                List<Integer> right = helper(expression.substring(i+1)); 
                
                for(int l : left){
                    for(int r : right){
                        if(op == '+') res.add(l + r); 
                        if(op == '-') res.add(l - r); 
                        if(op == '*') res.add(l * r); 
                    }
                }
            }
        }

        memo.put(expression,res); 

        return res; 
    }
}