class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> answer = new ArrayList<>(); 
        int left = 0, right = matrix[0].length - 1; 
        int bottom = matrix.length-1, top = 0; 
        int dir = 0; 
        while(answer.size() < matrix[0].length * matrix.length){
            if(dir == 0){
                for(int i = left; i <= right; i++){
                    answer.add(matrix[top][i]); 
                }
                top++; 
                dir = 1; 
            } else if(dir == 1){
                for(int i = top; i <= bottom; i++){
                    answer.add(matrix[i][right]); 
                }
                right--; 
                dir = 2; 
            } else if(dir == 2){
                for(int i = right; i >= left; i--){
                    answer.add(matrix[bottom][i]); 
                }
                bottom--; 
                dir = 3; 
            } else if(dir == 3){
                for(int i = bottom; i >= top; i--){
                    answer.add(matrix[i][left]); 
                }
                left++; 
                dir = 0; 
            }
        }

        return answer; 
    }
}