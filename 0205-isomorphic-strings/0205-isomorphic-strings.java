class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character,Character> hashMap = new HashMap<>(); 
        Set<Character> mappedChar = new HashSet<>(); 

        for(int i = 0; i < s.length(); i++){
            char left = s.charAt(i); 
            char right = t.charAt(i); 

            if(hashMap.containsKey(left) && hashMap.get(left) != right) return false; 
            if(!hashMap.containsKey(left) && mappedChar.contains(right)) return false; 

            hashMap.put(left, right); 
            mappedChar.add(right); 
        }

        return true; 
    }
}