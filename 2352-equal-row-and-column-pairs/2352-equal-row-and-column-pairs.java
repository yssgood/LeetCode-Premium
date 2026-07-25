class Solution {
    public int equalPairs(int[][] grid) {
        int n = grid.length; 
        Map<String,Integer> rowMap = new HashMap<>(); 
        Map<String,Integer> colMap = new HashMap<>(); 
        
        for(int i = 0; i < n; i++){
            StringBuilder row = new StringBuilder(); 
            StringBuilder col = new StringBuilder(); 
            for(int j = 0; j < n; j++){
                row.append(String.valueOf(grid[i][j])).append(","); 
                col.append(String.valueOf(grid[j][i])).append(","); 
            }
            rowMap.merge(row.toString(),1,Integer::sum); 
            colMap.merge(col.toString(),1,Integer::sum); 
        }

        int answer = 0; 
        for(var e: rowMap.entrySet()){
            if(colMap.containsKey(e.getKey())) answer += (e.getValue() * colMap.get(e.getKey())); 
        }

        return answer; 
    }
}