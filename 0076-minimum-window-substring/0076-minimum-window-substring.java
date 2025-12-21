class Solution {
    public String minWindow(String s, String t) {
        int currLength = 0; 
        Map<Character,Integer> hashMap = new HashMap<>(); 
        int startIndex = 0, endIndex = 0; 
        int start = 0, end = 0; 
        int minLength = Integer.MAX_VALUE; 
        for(char c : t.toCharArray()) hashMap.put(c, hashMap.getOrDefault(c,0) + 1); 
        while(end < s.length()){
            char curr = s.charAt(end); 
            if(hashMap.getOrDefault(curr,0) > 0){
                currLength++; 
            }
            hashMap.put(curr, hashMap.getOrDefault(curr,0) - 1); 
            while(currLength >= t.length()){
                if(end - start + 1 < minLength){
                    startIndex = start; 
                    endIndex = end; 
                    minLength = end - start + 1; 
                }
                char prev = s.charAt(start); 
                hashMap.put(prev, hashMap.get(prev) + 1); 
                if(hashMap.get(prev) > 0) currLength--; 
                start++; 
            }

            end++; 
        }

        return minLength == Integer.MAX_VALUE ? "" : s.substring(startIndex,endIndex+1); 
    }
}