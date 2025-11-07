class Solution {
    public int lengthOfLongestSubstring(String s) {
        int start = 0, end = 0; 
        int answer = 0; 
        Map<Character,Integer> hashMap = new HashMap<>();
        while(end < s.length()){
            hashMap.put(s.charAt(end), hashMap.getOrDefault(s.charAt(end),0) + 1); 
            while(hashMap.get(s.charAt(end)) > 1){
                hashMap.put(s.charAt(start), hashMap.get(s.charAt(start)) - 1); 
                if(hashMap.get(s.charAt(start)) <= 0){
                    hashMap.remove(s.charAt(start)); 
                }
                start++; 
            }

            answer = Math.max(answer, end - start + 1); 
            end++; 
        }
        return answer; 
    }
}