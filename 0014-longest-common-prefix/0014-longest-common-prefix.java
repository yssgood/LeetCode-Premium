class Solution {
    public String longestCommonPrefix(String[] strs) {
        String answer = strs[0]; 
        int len = strs[0].length(); 
        for(int i = 1; i < strs.length; i++){
            while(strs[i].startsWith(answer) != true){
                answer = answer.substring(0, len--);
            }
        }
        return answer; 
    }
}