class Solution {
    public String reverseWords(String s) {
        StringBuilder sb = new StringBuilder(s); 
        StringBuilder answer = new StringBuilder(); 
        sb.reverse(); 

        int start = 0;
        int end = 0; 
        while(end < sb.length()){
            while(start < sb.length() && !Character.isLetterOrDigit(sb.charAt(start))) start++; 
            end = start; 
            while(end < sb.length() && Character.isLetterOrDigit(sb.charAt(end))) end++; 

            StringBuilder tmp = new StringBuilder(sb.substring(start, end)); 
            tmp.reverse(); 
            if(tmp.length() > 0) answer.append(tmp).append(" "); 
            start = end; 
            end++; 
        }
        answer.deleteCharAt(answer.length()-1); 
        return answer.toString(); 
    }
}