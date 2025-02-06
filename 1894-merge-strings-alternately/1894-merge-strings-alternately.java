class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder sb = new StringBuilder(); 
        int p1 = 0, p2 = 0; 
        while(p1 < word1.length() && p2 < word2.length()){
            char a = '!';  
            char b = '!'; 

            if(p1 < word1.length()){
                a = word1.charAt(p1); 
            }
            if(p2 < word2.length()){
                b = word2.charAt(p2); 
            }

            if(a != '!'){
                sb.append(a); 
            }
            if(b != '!'){
                sb.append(b); 
            }

            p1++;
            p2++; 
        }

        if(p1 < word1.length()){
            sb.append(word1.substring(p1)); 
        } 
        if(p2 < word2.length()){
            sb.append(word2.substring(p2)); 
        }
        return sb.toString(); 
    }
}