class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> answer; 
        map<char,int> hashMap; 
        for(int i = 0; i < s.length(); i++){
            hashMap[s[i]] = i; 
        }
        int maxIndex = 0; 
        int lastIndex = 0; 
        for(int i = 0; i < s.length(); i++){
            maxIndex = max(maxIndex, hashMap[s[i]]); 

            if(i == maxIndex){
                answer.push_back(i - lastIndex + 1); 
                lastIndex = i + 1; 
            }
        }
        return answer; 
    }
};