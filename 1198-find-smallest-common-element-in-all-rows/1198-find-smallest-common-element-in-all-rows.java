class Solution {
    public int smallestCommonElement(int[][] mat) {
        int m = mat.length, n = mat[0].length; 
        Map<Integer,Integer> hashMap = new HashMap<>(); 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                hashMap.merge(mat[i][j],1,Integer::sum); 
                if(hashMap.get(mat[i][j]) == m) return mat[i][j]; 
            }
        }
        return -1; 
    }
}