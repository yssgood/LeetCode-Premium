class Solution {
    public int findLonelyPixel(char[][] picture) {
        HashMap<Integer,Integer> rowMap = new HashMap<>(); 
        HashMap<Integer,Integer> colMap = new HashMap<>(); 
        int answer = 0; 
        for(int i = 0; i < picture.length; i++){
            for(int j = 0; j < picture[i].length; j++){
                if(picture[i][j] == 'B'){
                    rowMap.put(i,rowMap.getOrDefault(i,0) + 1);
                    colMap.put(j,colMap.getOrDefault(j,0) + 1); 
                }
            }
        }

        for(int i = 0; i < picture.length; i++){
            for(int j = 0; j < picture[i].length; j++){
                if(picture[i][j] == 'B' && rowMap.get(i) == 1 && colMap.get(j) == 1){
                    answer++; 
                }
            }
        }
        return answer; 
    }
}