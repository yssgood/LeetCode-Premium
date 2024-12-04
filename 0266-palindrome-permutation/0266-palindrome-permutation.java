class Solution {
    public boolean canPermutePalindrome(String s) {
        HashMap<Character,Integer> hashMap = new HashMap<>(); 
        for(Character c : s.toCharArray()){
            if(hashMap.containsKey(c)){
                hashMap.put(c, hashMap.get(c) - 1); 
                if(hashMap.get(c) <= 0) hashMap.remove(c); 
            } else{
                hashMap.put(c, 1); 
            }
        }
        //System.out.print(hashMap.size()); 
        return hashMap.size() > 1 ? false : true; 
    }
}