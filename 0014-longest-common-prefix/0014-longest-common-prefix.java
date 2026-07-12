class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs); 
        StringBuilder sb = new StringBuilder(strs[0]);
        int len = sb.length(); 
        //System.out.print(len); 
        for(int i = 1; i < strs.length; i++){
            while(!strs[i].startsWith(sb.toString())){
                sb = new StringBuilder(sb.substring(0,len--)); 
                if(len < 0) return ""; 
            }
        }
        return sb.toString(); 
    }
}