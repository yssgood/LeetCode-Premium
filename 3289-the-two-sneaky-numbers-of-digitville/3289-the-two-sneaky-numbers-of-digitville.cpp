class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> answer; 
        map<int,int> hashMap; 
        for(int n : nums) hashMap[n]++; 
        for(auto& it : hashMap) if(it.second > 1) answer.push_back(it.first);
        return answer; 
    }
};