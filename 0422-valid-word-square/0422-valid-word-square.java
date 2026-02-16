class Solution {
    public boolean validWordSquare(List<String> words) {
        
        for(int i = 0; i < words.size(); i++){
            String row = words.get(i); 
            StringBuilder sb = new StringBuilder(); 
            for(int j = 0; j < words.get(i).length(); j++){
                if (j >= words.size() || i >= words.get(j).length()) {
                    return false;
                }
                sb.append(words.get(j).charAt(i)); 
            }
            //System.out.println(sb); 
            if(!row.equals(sb.toString())) return false; 
        }

        return true; 
    }
}

/*
["ball",
 "asee",
 "let",
 "lep"]

*/