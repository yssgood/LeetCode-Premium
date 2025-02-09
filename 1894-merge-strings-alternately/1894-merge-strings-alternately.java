class Solution {
    public String mergeAlternately(String word1, String word2) {
        int min_len = Math.min(word1.length(), word2.length()); 
        StringBuilder sb = new StringBuilder(); 
        for(int i = 0 ; i < min_len; i++){
            sb.append(word1.charAt(i)); 
            sb.append(word2.charAt(i)); 
        }

        if(word1.length() > word2.length()){
            sb.append(word1.substring(min_len));
        } else if(word1.length () < word2.length()){
            sb.append(word2.substring(min_len)); 
        }

        return sb.toString(); 
    }
}