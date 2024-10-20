class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        unordered_map<int,int> hashMap;
        int start = 0, end = 0; 
        int count = 0, n = s.size(); 

        while(end < n){
            hashMap[s[end]]++; 
            while(hashMap[s[end]] >= k){
                count += n - end; 
                hashMap[s[start]]--;
                start++; 
            }
            end++; 
        }
        return count; 
    }
};