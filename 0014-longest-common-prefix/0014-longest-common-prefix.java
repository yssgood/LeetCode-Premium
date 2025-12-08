class Solution {
    public String longestCommonPrefix(String[] strs) {
        String answer = strs[0]; 
        int n = answer.length(); 
        for(int i = 1; i < strs.length; i++){
            while(strs[i].startsWith(answer) == false){
                answer = answer.substring(0,n--); 
            }
        }
        return answer; 
    }
}