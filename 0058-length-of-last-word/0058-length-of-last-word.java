class Solution {
    public int lengthOfLastWord(String s) {
        int second = s.length()-1; 
        while(second >= 0 && Character.isSpace(s.charAt(second))) second--; 
        
        int first = second; 
        while(first >= 0 && Character.isLetter(s.charAt(first)))  first--; 
        return second - first; 
    }
}