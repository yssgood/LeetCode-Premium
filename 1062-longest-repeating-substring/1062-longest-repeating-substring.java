class Solution {
    public int longestRepeatingSubstring(String s) {
        int left = 1, right = s.length(); 
        int candidate = 0; 
        while(left <= right){
            int mid = left + (right - left) / 2; 
            if(possible(s,mid)){
                candidate = mid;
                left = mid + 1; 
            } else{
                right = mid - 1; 
            }
        }
        return candidate;
    }
    public boolean possible(String s, int length){
        Set<String> check = new HashSet<>(); 
        for(int i = 0; i <= s.length() - length;i++){
            String substr = s.substring(i, i + length); 
            if(check.contains(substr)) return true; 
            check.add(substr); 
        }
        return false; 
    }
}