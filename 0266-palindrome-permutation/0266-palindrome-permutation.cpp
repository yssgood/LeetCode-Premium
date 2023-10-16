class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char,int> hashMap; 
        int final_cnt = 0; 

        for(char& c : s){
            if(hashMap.count(c)) hashMap[c]++; 
            else hashMap[c] = 1; 
        }

        for(auto& it : hashMap){
            if(it.second % 2 == 1) final_cnt++; 
        }

        return final_cnt > 1 ? false : true; 
    }
};