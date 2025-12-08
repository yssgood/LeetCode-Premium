class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs); 
        StringBuilder sb = new StringBuilder(); 
        int n = strs.length-1; 
        int index = Math.min(strs[0].length(), strs[strs.length-1].length()); 
        for(int i = 0; i < index && strs[0].charAt(i) == strs[n].charAt(i) ; i++){
            sb.append(strs[0].charAt(i)); 
        }
        return sb.toString(); 
    }
}