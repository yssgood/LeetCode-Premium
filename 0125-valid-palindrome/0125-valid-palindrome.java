class Solution {
    public boolean isPalindrome(String s) {
        int start = 0; 
        int end = s.length()-1; 
        while(start < end){
            while(start < end && !Character.isLetterOrDigit(s.charAt(start))) start++; 
            while(start < end && !Character.isLetterOrDigit(s.charAt(end))) end--;

            Character a = Character.toUpperCase(s.charAt(start)); 
            Character b = Character.toUpperCase(s.charAt(end)); 

            if(a != b) return false;
            start++;
            end--; 
        }

        return true; 
    }
}