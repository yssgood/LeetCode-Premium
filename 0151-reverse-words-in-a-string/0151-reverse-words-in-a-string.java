class Solution {
    public String reverseWords(String s) {
        StringBuilder sb = new StringBuilder(s); 
        StringBuilder answer = new StringBuilder(); 
        sb.reverse(); 
        int start = 0, end = 0; 
        int n = s.length(); 
        while(end < n){
            while(start < n && sb.toString().charAt(start) == ' ') start++; 
            end = start; 
            while(end < n && sb.toString().charAt(end) != ' ') end++;

            StringBuilder tmp = new StringBuilder(sb.toString().substring(start, end)); 
            tmp.reverse(); 
            if(tmp.length() > 0) answer.append(tmp.toString()).append(" "); 
            start = end; 
        }

        answer.deleteCharAt(answer.length()-1); 
        
        return answer.toString(); 
    }
}