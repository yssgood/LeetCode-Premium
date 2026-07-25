class Solution {
    public int[][] multiply(int[][] mat1, int[][] mat2) {
        int m = mat1.length, k = mat1[0].length;
        int n = mat2[0].length;

        int[][] answer = new int[m][n];   // m × n

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {        // 결과 열: 0~n
                int sum = 0;
                for (int l = 0; l < k; l++) {    // 내적 인덱스: 0~k
                    sum += mat1[i][l] * mat2[l][j];
                }
                answer[i][j] = sum;
            }
        }

        return answer;
    }
}