class Solution {
    public String compressedString(String word) {
        StringBuilder sb = new StringBuilder(); 
        int count = 1; 
        char curr = word.charAt(0); 

        for(int i = 1; i < word.length(); i++){
            char compare = word.charAt(i); 

            if(curr == compare){
                count++; 
                if(count > 9){
                    sb.append(count - 1).append(curr); 
                    count = 1; 
                }
            } else{
                sb.append(count).append(curr); 
                curr = compare; 
                count = 1; 
            }
        }

        sb.append(count).append(curr); 

        return sb.toString();  
    }
}