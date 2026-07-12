class Solution {
    public int lengthOfLastWord(String s) {
        StringBuilder sb = new StringBuilder(); 
        int start = 0, end = 0; 
        int answer = 0; 
        int n = s.length(); 
        while(end < n){
            while(end < n && s.charAt(end) == ' ') end++; 
            start = end; 
            while(end< n && Character.isLetter(s.charAt(end))) end++; 
            if(!s.substring(start,end).isEmpty()){
                sb.append(s.substring(start,end)).append(' '); 
                answer = s.substring(start,end).length(); 
            }
            end++; 
        }

        

        return answer; 
    }
}