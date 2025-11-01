class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer; 
        map<string, vector<string>> hashMap; 

        for(string& s : strs){
            string tmp = s; 
            sort(tmp.begin(), tmp.end()); 

            hashMap[tmp].push_back(s); 
        }

        for(auto& it : hashMap){
            answer.push_back(it.second); 
        }

        return answer; 
    }
};