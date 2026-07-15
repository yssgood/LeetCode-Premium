class Solution {
    public String simplifyPath(String path) {
        path = path + "/";   // 마지막에 / 추가
        Deque<StringBuilder> stack = new ArrayDeque<>(); 


        int end = 0; 
        StringBuilder sb = new StringBuilder(); 
        int n = path.length(); 

        while(end < n){
            char curr = path.charAt(end); 
            
            if(curr != '/'){
                sb.append(path.charAt(end)); 
            } else{
                if(!sb.toString().equals(".") && !sb.toString().equals("..") && !sb.isEmpty()){
                    stack.push(sb); 
                } else{
                    if(sb.toString().equals("..") && !stack.isEmpty()){
                        stack.pop(); 
                    }
                }
                sb = new StringBuilder(); 
            }
            end++; 
        }

        // if(!sb.isEmpty()) stack.push(sb); 

        StringBuilder result = new StringBuilder();
        while(!stack.isEmpty()){
            result.append("/").append(stack.pollLast());
        }

        return result.length() == 0 ? "/" : result.toString();
    }
}