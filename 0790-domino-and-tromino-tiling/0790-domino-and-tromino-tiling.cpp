/*
Distinct Ways

Statement
Given a target find a number of distinct ways to reach the target.


Approach
Sum all possible ways to reach the current state.

routes[i] = routes[i-1] + routes[i-2], ... , + routes[i-k]

*/ 


class Solution {
public:
    int numTilings(int n) {
        int MOD = 1'000'000'007;
        // handle base case scenarios
        if (n <= 2) {  
            return n;
        }
        // f[k]: number of ways to "fully cover a board" of width k
        long f[1001];
        // p[k]: number of ways to "partially cover a board" of width k
        long p[1001];
        // initialize f and p with results for the base case scenarios
        f[1] = 1;
        f[2] = 2;
        p[2] = 1;
        for (int k = 3; k < n + 1; ++k) {
            f[k] = (f[k - 1] + f[k - 2] + 2 * p[k - 1]) % MOD;
            p[k] = (p[k - 1] + f[k - 2]) % MOD; 
        }
        return static_cast<int>(f[n]);
    }
};