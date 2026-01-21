class Solution {
    public int findLonelyPixel(char[][] picture) {
        Map<Integer,Integer> rowMap = new HashMap<>(); 
        Map<Integer,Integer> colMap = new HashMap<>(); 

        int m = picture.length; 
        int n = picture[0].length; 

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(picture[i][j] == 'B'){
                    rowMap.put(i, rowMap.getOrDefault(i,0) + 1); 
                    colMap.put(j, colMap.getOrDefault(j,0) + 1); 
                }
            }
        }

        int count = 0; 

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(picture[i][j] == 'B' && rowMap.get(i) == 1 && colMap.get(j) == 1){
                    count++; 
                }
            }
        }

        return count; 
    }
}