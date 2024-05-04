class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> hashMap; 
        set<int> hashSet; 
        for(int n : arr) hashMap[n]++; 


        for(auto& it : hashMap) hashSet.insert(it.second); 

        return  hashSet.size() == hashMap.size(); 
    }
};