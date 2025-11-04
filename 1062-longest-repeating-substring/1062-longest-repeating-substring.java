class Solution {
    public int longestRepeatingSubstring(String s) {
        //brute force would be ok 
        Set<String> hashSet = new HashSet<>(); 
        int answer = 0; 
        for(int i = 0; i < s.length(); i++){
            for(int j = i+1; j <= s.length(); j++){
                String tmp = s.substring(i,j); 
                if(hashSet.contains(tmp)){
                    answer = Math.max(answer, j - i); 
                }
                hashSet.add(tmp); 
            }
        }

        return answer; 
    }
}