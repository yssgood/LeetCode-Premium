class Solution {
    public int longestRepeatingSubstring(String s) {
        int max_ = 0; 
        int n = s.length(); 
        
        Set<String> set = new HashSet<>(); 
        for(int i = 0; i < n; i++){
            int count = 0; 
            for(int j = i+1; j <= n; j++){
                String tmp = s.substring(i,j); 
                if(set.contains(tmp)){
                    count++; 
                }
                set.add(tmp); 
            }
            max_ = Math.max(max_, count); 
        }

        return max_; 
    }
}