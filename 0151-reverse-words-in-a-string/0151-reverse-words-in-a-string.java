class Solution {
    public String reverseWords(String s) {
        StringBuilder sb = new StringBuilder(s); 
        StringBuilder answer = new StringBuilder(); 

        sb.reverse(); 

        int start = 0, end = 0; 
        while(end < sb.length()){
            while(start < sb.length() && !Character.isLetterOrDigit(sb.charAt(start))) start++;
            if(start >= sb.length()) break; 
            end = start; 
            while(end < sb.length() && Character.isLetterOrDigit(sb.charAt(end))) end++; 

            StringBuilder tmp = new StringBuilder(sb.substring(start,end)); 
            tmp.reverse(); 
            answer.append(tmp).append(" "); 
            end++; 
            start = end; 
        }
        answer.deleteCharAt(answer.length()-1);
        return answer.toString(); 
    }
}