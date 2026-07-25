class Solution {
    public boolean validWordSquare(List<String> words) {
        int n = words.size(); 
        for(int i = 0; i < n; i++){
            String curr = words.get(i); 
            for(int j = 0; j < curr.length(); j++){
                if(j >= n || i >= words.get(j).length() || curr.charAt(j) != words.get(j).charAt(i)) return false; 
            }
        }
        return true; 
    }
}