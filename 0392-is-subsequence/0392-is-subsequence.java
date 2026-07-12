class Solution {
    public boolean isSubsequence(String s, String t) {
        int start = 0, end = 0; 
        while(start < s.length() && end < t.length()){
            if(s.charAt(start) == t.charAt(end)){
                start++; 
            }
            end++; 
        }
        return start >= s.length(); 
    }
}