class Solution {
    public void reverse(char[] s, int start, int end){
        while(start < end){
            char t = s[start]; 
            s[start] = s[end]; 
            s[end] = t; 
            start++;
            end--; 
        }
    }
    public void reverseWords(char[] s) {
        reverse(s,0,s.length-1); 
        int start = 0; 
        int end = 0; 
        while(end < s.length){
            if(s[end] == ' '){
                reverse(s,start,end-1); 
                start = end + 1; 
            }
            end++; 
        }
        reverse(s,start,end-1); 
    }
}