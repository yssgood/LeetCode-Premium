class Solution {
public:
    int numTilings(int n) {
        if(n <= 2) return n; 
        long MOD = pow(10,9) + 7; 
        vector<long> half(n+1,0); 
        vector<long> full(n+1,0);

        full[1] = 1; 
        full[2] = 2; 
        half[2] = 1; 

        for(int i=  3; i <= n; i++){
            full[i] = (full[i-1] + full[i-2] + 2 * half[i-1]) % MOD;
            half[i] = (half[i-1] + full[i-2]) % MOD; 
        }
        return full[n]; 
    }
};