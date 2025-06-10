class Solution {
    public int maxDifference(String s) {
        Map<Character,Integer> hashMap  = new HashMap<>(); 
        for(char c : s.toCharArray()){
            hashMap.put(c, hashMap.getOrDefault(c,0) + 1);    
        }

        int max_odd = Integer.MIN_VALUE; 
        int max_even = Integer.MAX_VALUE; 
        for(char c : s.toCharArray()){
            int freq = hashMap.get(c); 
            if(freq % 2 != 0) max_odd = Math.max(max_odd,freq); 
            else max_even = Math.min(max_even,freq); 
        }

        return max_odd - max_even; 
    }
}