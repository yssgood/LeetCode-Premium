class Solution {
    public boolean isAnagram(String s, String t) {
        char[] map = new char[26]; 
        for(char c : s.toCharArray()) map[c-'a']++; 
        for(char c : t.toCharArray()) map[c-'a']--; 

        for(int i = 0; i < 26; i++){
            if(map[i] != 0) return false; 
        }
        return true; 
    }
}