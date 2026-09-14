class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        Map<Character,Integer> hashMap = new HashMap<>(); 
        int start = 0, end = 0; 
        int answer = 0; 
        while(end < s.length()){
            char curr = s.charAt(end); 
            hashMap.merge(curr,1,Integer::sum); 
            while(hashMap.size() > 2){
                char left = s.charAt(start); 
                hashMap.merge(left,-1,Integer::sum); 
                if(hashMap.get(left) == 0) hashMap.remove(left); 
                start++; 
            }
            answer = Math.max(answer, end - start + 1); 
            end++; 
        }
        return answer; 
    }
}