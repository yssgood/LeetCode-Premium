class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder sb = new StringBuilder(); 
        int p1 = 0, p2 = 0; 
        int n = word1.length(), m = word2.length(); 

        while(p1 < n && p2 < m){
            char a = word1.charAt(p1); 
            char b = word2.charAt(p2); 


            sb.append(a).append(b); 
            p1++;
            p2++; 
        }

        if(p1 < n) sb.append(word1.substring(p1));
        if(p2 < m) sb.append(word2.substring(p2)); 

        return sb.toString(); 
    }
}