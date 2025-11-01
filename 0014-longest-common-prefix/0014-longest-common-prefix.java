class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs); 

        int len = Math.min(strs[0].length(), strs[strs.length-1].length()); 
        StringBuilder answer = new StringBuilder(); 
        for(int i = 0; i < len; i++){
            if(strs[0].charAt(i) == strs[strs.length-1].charAt(i)){
                answer.append(strs[0].charAt(i)); 
            } else{
                break; 
            }
        }

        return answer.toString(); 
    }
}