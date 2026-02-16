class Solution {
    public boolean validWordSquare(List<String> words) {
        int m = words.size();  
        for(int i = 0; i < m; i++){
            String original = words.get(i); 
            StringBuilder tmp = new StringBuilder(); 
            for(int j = 0; j < m; j++){
                if(i >= words.get(j).length()) break; 
                tmp.append(words.get(j).charAt(i)); 
            }
            if(!original.equals(tmp.toString())) return false; 
        }
        return true; 
    }
}