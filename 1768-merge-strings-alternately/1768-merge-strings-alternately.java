class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder sb = new StringBuilder(); 
        int p1 = 0, p2 = 0; 

        while(p1 < word1.length() || p2 < word2.length()){
            
            char first = ' ', second = ' '; 

            if(p1 < word1.length()){
                first = word1.charAt(p1); 
            }

            if(p2 < word2.length()){
                second = word2.charAt(p2); 
            }

            if(first != ' ') sb.append(first); 
            if(second != ' ') sb.append(second); 

            p1++;
            p2++; 
        }

        return sb.toString(); 
    }
}