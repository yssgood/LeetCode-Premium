class Solution {
    int index = 0; 
    public String countOfAtoms(String formula) {

        Stack<Map<String, Integer>> stack = new Stack<>();
        stack.push(new HashMap<>());

        int n = formula.length(); 
        int i = 0;  
        
        while(i < n){
            char c = formula.charAt(i); 

            if(c == '('){
                stack.push(new HashMap<>()); 
                i++; 

            } else if(c == ')'){
                i++; 
                int start = i; 
                while(i < n && Character.isDigit(formula.charAt(i))) i++; 

                int multiplier = (start < i) ? Integer.parseInt(formula.substring(start,i)) : 1; 

                Map<String,Integer> top = stack.pop(); 

                for(String key : top.keySet()) {
                    int cnt = top.get(key) * multiplier; 
                    stack.peek().put(key, stack.peek().getOrDefault(key,0) + cnt); 
                }

            } else{
                int start = i; 
                i++; 
                while(i < n && Character.isLowerCase(formula.charAt(i))) i++; 
                String atom = formula.substring(start,i);
                start = i; 
                while(i < n && Character.isDigit(formula.charAt(i))) i++; 
                int count = (start < i) ? Integer.parseInt(formula.substring(start,i)) : 1; 
                stack.peek().put(atom, stack.peek().getOrDefault(atom,0) + count); 
            }
        }

        Map<String, Integer> result = stack.pop();
        TreeMap<String,Integer> sorted = new TreeMap<>(result);  

        StringBuilder sb = new StringBuilder(); 
        for(String key : sorted.keySet()){
            sb.append(key); 
            int cnt = sorted.get(key); 
            if(cnt > 1) sb.append(cnt); 
        }

        return sb.toString(); 
    }
}