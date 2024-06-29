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
        if(n <= 2){
            return n; 
        }

        long full[1001]; 
        long part[1001]; 

        full[1] = 1; 
        full[2] = 2; 
        part[2] = 1; 

        for(int i = 3; i < n + 1; ++i){
            full[i] = (full[i-1] + full[i-2] + 2 * part[i - 1]) % MOD; 
            part[i] = (part[i-1] + full[i - 2]) % MOD; 
        }

        return full[n]; 
    }
};