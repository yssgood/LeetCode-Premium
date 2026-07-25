class Solution {
    public boolean validWordSquare(List<String> words) {
        int n = words.size(); 
        for(int i = 0; i < n; i++){
            String row = words.get(i); 
            String col = ""; 
            for(int j = 0; j < n; j++){
                if(i >= words.get(j).length()) break; 
                col += words.get(j).charAt(i); 
            }
            if(!row.equals(col)) return false; 
        }
        return true; 
    }
}