class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        Map<Character, Integer> hashMap = new HashMap<>(); 
        int answer = 0, start = 0, end = 0; 

        while(end < s.length()){
            char curr = s.charAt(end); 
            hashMap.put(curr, hashMap.getOrDefault(curr,0) + 1); 
            while(hashMap.size() > k){
                char startChar = s.charAt(start); 
                hashMap.put(startChar, hashMap.get(startChar) - 1); 

                if(hashMap.get(startChar) == 0){
                    hashMap.remove(startChar); 
                }
                start++; 
            }
            answer = Math.max(answer, end - start + 1); 
            end++; 
        }
        return answer; 
    }
}