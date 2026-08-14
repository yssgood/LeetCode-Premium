class Solution {
    public int longestRepeatingSubstring(String s) {
        Set<String> check = new HashSet<>(); 
        int n = s.length(); 
        int answer = 0; 
        for(int i = 0; i < s.length(); i++){
            int count = 0; 
            for(int j = i + 1; j <= n; j++){
                String substr = s.substring(i,j); 
                if(check.contains(substr)) count++; 
                check.add(substr); 
            }
            answer = Math.max(answer, count); 
        }
        return answer; 
    }
}