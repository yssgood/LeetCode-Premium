class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        Map<Character,Integer> hashMap = new HashMap<>(); 
        int start = 0; 
        int end = 0; 
        int answer = 0; 
        while(end < s.length()){
            hashMap.put(s.charAt(end), hashMap.getOrDefault(s.charAt(end),0)+1); 
            
            while(hashMap.size() > k){
                char startChar = s.charAt(start);  
                hashMap.put(startChar, hashMap.get(startChar) - 1); 
                if(hashMap.get(s.charAt(start)) <= 0) hashMap.remove(s.charAt(start)); 
                start++; 
            }

            answer = Math.max(answer, end - start + 1);  
            end++; 
        }

        return answer; 
    }
}