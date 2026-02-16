class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs); 
        String answer = ""; 
        for(int i = 0; i < Math.min(strs[0].length(), strs[strs.length-1].length()); i++){
            if(strs[0].charAt(i) != strs[strs.length-1].charAt(i)) break; 
            answer += strs[0].charAt(i); 
        }
        return answer; 
    }
}