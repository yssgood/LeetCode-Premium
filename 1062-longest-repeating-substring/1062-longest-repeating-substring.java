class Solution {
    public int longestRepeatingSubstring(String s) {
        Set<String> set = new HashSet<>(); 
        int n = s.length(); 
        int answer = 0; 
        for(int i = 0; i < n; i++){
            int count = 0; 
            for(int j = i+1; j <= n; j++){
                String tmp = s.substring(i,j); 
                if(set.contains(tmp)) count++; 
                set.add(tmp); 
            }
            answer = Math.max(answer,count); 
        }

        return answer; 
    }
}