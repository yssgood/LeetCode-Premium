class Solution {
    public boolean isMatch(String s, String p) {
        int n = s.length();
        int m = p.length();

        boolean[][] dp = new boolean[n + 1][m + 1];

        dp[0][0] = true;

        // 패턴이 "*", "a*", "a*b*", ... 등으로 시작하는 경우 처리
        for (int j = 2; j <= m; j++) {
            if (p.charAt(j - 1) == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                char sc = s.charAt(i - 1);
                char pc = p.charAt(j - 1);

                // Case 1: 단일 문자 매칭 or '.'
                if (pc == sc || pc == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                // Case 2: '*' 처리
                else if (pc == '*') {
                    
                    // '*' 앞 문자
                    char prev = p.charAt(j - 2);

                    // A: zero occurrence → '*' 앞 문자 0번 사용
                    if (dp[i][j - 2]) {
                        dp[i][j] = true;
                    }

                    // B: one or more occurrence → '*' 앞 문자가 현재 문자와 매칭될 때
                    if (prev == sc || prev == '.') {
                        if (dp[i - 1][j]) {
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }

        return dp[n][m];
    }
}
