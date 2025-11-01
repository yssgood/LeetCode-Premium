class Solution {
    public String longestCommonPrefix(String[] strs) {
        String first = strs[0]; 
        int len = first.length(); 
        for(int i = 1; i < strs.length; i++){
            while(strs[i].indexOf(first) != 0){
                first = first.substring(0,len--); 
            }
        }
        return first; 
    }
}