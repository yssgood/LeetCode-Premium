class Solution {
    public int findLonelyPixel(char[][] picture) {
        Map<Integer,Integer> rowMap = new HashMap<>(); 
        Map<Integer,Integer> colMap = new HashMap<>(); 
        int n = picture.length, m = picture[0].length;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(picture[i][j] == 'B'){
                    rowMap.merge(i,1,Integer::sum); 
                    colMap.merge(j,1,Integer::sum); 
                }
            }
        }

        int answer = 0; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(picture[i][j] == 'B' && rowMap.get(i) == 1 && colMap.get(j) == 1) answer++; 
            }
        }

        return answer; 
    }
}