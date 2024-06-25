class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }
        int check = t.length(); 
        //unordered_map<char,int> hashMap; 
        vector<int> hashMap(128, 0); 
        for(char& c : t) hashMap[c]++; 

        int start = 0, end = 0; 
        string answer = s + "AA"; 
        int startIndex = 0, minLen = INT_MAX; 
        while(end < s.length()){
            //요구 사항 확인 
            //check -= hashMap.count(s[end]) ? 1 : 0; 
            if(hashMap[s[end++]]-- > 0){
                check--; 
                //hashMap[s[end]]--;
            }

            //범위 조정 
            while(check == 0){
                //cout << end << ' ' << start << ' ' << answer.length() << endl; 
                if(end - start  < minLen){
                    //answer = s.substr(start, end - start); 
                    startIndex = start;  
                    minLen = end - start; 
                }

                //check += hashMap.count(s[start]) ? 1 : 0; 
                // if(hashMap.count(s[start])){
                //     hashMap[s[start]]++; 
                //     if(hashMap[s[start]] > 0) check++; 
                // }
                if(hashMap[s[start++]]++ == 0){
                    check++; 
                }
                //start++; 
            }



            //범위 증가 
            //end++; 
        }
        
        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen); 
    }
};