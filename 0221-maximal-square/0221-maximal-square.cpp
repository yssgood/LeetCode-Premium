class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // 1) 예외 처리: 빈 행렬인 경우
        if (matrix.empty() || matrix[0].empty()) 
            return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int max_side = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 현재 칸이 '1'일 때만 정사각형 확장 가능
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        // 첫 행 또는 첫 열은 자신이 1이면 무조건 1x1
                        dp[i][j] = 1;
                    } else {
                        // 상·좌·좌상 의 최소값 + 1
                        dp[i][j] = 1 + min({
                            dp[i-1][j],   // 위
                            dp[i][j-1],   // 왼쪽
                            dp[i-1][j-1]  // 대각선 위 왼쪽
                        });
                    }
                    // 최댓값 갱신
                    max_side = max(max_side, dp[i][j]);
                }
                // matrix[i][j] == '0' 인 경우 dp[i][j]는 0으로 남음
            }
        }

        // 넓이 = 한 변의 길이의 제곱
        return max_side * max_side;
    }
};
