class Solution {
    public String longestCommonPrefix(String[] strs) {
        String answer = strs[0]; 
        int length = answer.length(); 
        for(int i = 1; i < strs.length; i++){
            while(!strs[i].startsWith(answer)){
                answer = answer.substring(0, length--);
            }
        }
        return answer; 
    }
}