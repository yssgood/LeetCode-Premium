class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character,Integer> hashMap = new HashMap<>();
        for(char c : ransomNote.toCharArray()){
            hashMap.put(c, hashMap.getOrDefault(c,0) + 1);
        }
        for(char c : magazine.toCharArray()){
            if(hashMap.containsKey(c)) hashMap.put(c, hashMap.get(c) - 1); 
        }
        for(var e : hashMap.entrySet()){
            if(e.getValue() > 0) return false; 
        }
        return true; 
    }
}