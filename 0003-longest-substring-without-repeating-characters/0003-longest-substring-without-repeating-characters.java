class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character,Integer> hashMap = new HashMap<>(); 
        int start = 0, end = 0; 
        int answer = 0;
        while(end < s.length()){
            char curr = s.charAt(end); 
            hashMap.put(curr, hashMap.getOrDefault(curr,0)+1); 
            while(hashMap.get(curr) > 1){
                char prev = s.charAt(start); 
                hashMap.put(prev, hashMap.get(prev) - 1); 
                start++; 
            }
            answer = Math.max(answer, end -start + 1); 
            end++; 
        }

        return answer; 
    }
}