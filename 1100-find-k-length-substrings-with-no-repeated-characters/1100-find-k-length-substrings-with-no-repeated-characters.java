class Solution {
    public int numKLenSubstrNoRepeats(String s, int k) {
        Map<Character,Integer> hashMap = new HashMap<>(); 
        int start = 0, end = 0, answer = 0;  
        while(end < s.length()){
            char curr = s.charAt(end); 
            while(hashMap.containsKey(curr) || end - start + 1 > k){
                char prev = s.charAt(start); 
                hashMap.merge(prev, -1, Integer::sum); 
                if(hashMap.get(prev) <= 0) hashMap.remove(prev); 
                start++; 
            }

            if(end - start + 1 == k){
                answer++; 
            }

            hashMap.merge(curr,1,Integer::sum); 
            end++; 
        }

        return answer; 
    }
}