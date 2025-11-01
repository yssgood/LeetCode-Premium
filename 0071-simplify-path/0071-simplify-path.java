class Solution {
    public String simplifyPath(String path) {
        String[] words = path.split("/"); 
        Stack<String> stack = new Stack<>(); 

        for(String s : words){
            
            if(s.equals(".") || s.equals("..")){
                if(s.equals("..") && !stack.isEmpty()) stack.pop(); 
            } else{
                //System.out.print(s + " "); 
                if(s.length() > 0) stack.push(s); 
            }
        }

        StringBuilder sb = new StringBuilder(); 
        while(!stack.isEmpty()){
            StringBuilder lastPath = new StringBuilder(stack.pop()); 
            lastPath.reverse(); 
            sb.append("/").append(lastPath.toString()); 
            
        }

        sb.append("/"); 
        sb.reverse(); 
        if(sb.length() > 1) sb.deleteCharAt(sb.length()-1); 

        return sb.toString(); 
    }
}

/*
    foo 
                  home 

   /oof/emoh/
   /home/foo/

*/ 