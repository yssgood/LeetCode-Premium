class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int answer = 0; 
        int start = 0, end = 0; 
        Map<Character,Integer> hashMap = new HashMap<>(); 
        while(end < s.length()){
            char curr = s.charAt(end); 
            hashMap.merge(curr,1,Integer::sum); 
            while(hashMap.size() > k){
                char prev = s.charAt(start);
                hashMap.merge(prev,-1,Integer::sum); 
                if(hashMap.get(prev) <= 0) hashMap.remove(prev); 
                start++; 
            }
            answer = Math.max(answer, end - start + 1); 
            end++; 
        }

        return answer; 
    }
}