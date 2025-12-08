class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character,Character> hashMap = new HashMap<>(); 
        for(int i = 0; i < s.length(); i++){
            char sChar = s.charAt(i); 
            char tChar = t.charAt(i); 

            if(hashMap.containsKey(sChar) && hashMap.get(sChar) != tChar) return false; 
            
            hashMap.put(sChar, tChar); 
        }

        return true; 
    }
}