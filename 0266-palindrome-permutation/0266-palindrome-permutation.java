class Solution {
    public boolean canPermutePalindrome(String s) {
        Map<Character,Integer> hashMap = new HashMap<>(); 
        for(char c : s.toCharArray()) hashMap.merge(c,1,Integer::sum); 

        int count = 0; 
        for(var e : hashMap.entrySet()){
            if(e.getValue() % 2 != 0) count++;
            if(count > 1) return false; 
        }
        return true; 
    }
}