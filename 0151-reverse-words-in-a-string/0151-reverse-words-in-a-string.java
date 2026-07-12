class Solution {
    public String reverseWords(String s) {
        s = new StringBuilder(s).reverse().toString(); 
        int start = 0, end = 0; 
        int n = s.length(); 
        StringBuilder sb = new StringBuilder(); 

        while(end < n){
            while(end < n && Character.isSpace(s.charAt(end))) end++; 
            start = end; 
            while(end < n && s.charAt(end) != ' ') end++; 

            if(!s.substring(start,end).isEmpty()){
                StringBuilder tmp = new StringBuilder(s.substring(start,end)).reverse(); 
                sb.append(tmp).append(' '); 
            }
            end++; 
        }

        sb.deleteCharAt(sb.length()-1); 

        return sb.toString(); 
    }
}