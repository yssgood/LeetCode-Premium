class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int answer = 0; 
        int start = 0; 
        int end = 0;  
        HashMap<Character,Integer> hashMap = new HashMap<>(); 
        while(end < s.length()){
            hashMap.put(s.charAt(end), hashMap.getOrDefault(s.charAt(end),0) + 1); 
            while(hashMap.size() > k){
                hashMap.put(s.charAt(start),hashMap.get(s.charAt(start)) - 1);
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