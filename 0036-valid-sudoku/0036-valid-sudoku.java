class Solution {
    public boolean isValidSudoku(char[][] board) {
        Map<Integer,Set<Character>> rowMap = new HashMap<>(); 
        Map<Integer,Set<Character>> colMap = new HashMap<>(); 
        Map<Integer,Set<Character>> boxMap = new HashMap<>(); 

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue; 
                char c = board[i][j]; 
                
                int boxIndex = (i / 3) * 3 + (j / 3); 

                if(rowMap.containsKey(i) && rowMap.get(i).contains(c)) return false; 
                if(colMap.containsKey(j) && colMap.get(j).contains(c)) return false; 
                if(boxMap.containsKey(boxIndex) && boxMap.get(boxIndex).contains(c)) return false; 

                rowMap.computeIfAbsent(i, k -> new HashSet<>()).add(c); 
                colMap.computeIfAbsent(j, k -> new HashSet<>()).add(c); 
                boxMap.computeIfAbsent(boxIndex, k -> new HashSet<>()).add(c); 
            }
        }

        return true; 
    }
}