class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //hashMap 
        //1. loop.를 돌면서 각 숫자가 몇번 발견했는지를 확인한다. 
        //2. hashMap 을 탐색해서 문제가 요구하는 2번 이상의 값이 발견이 됐는지 => true  
        //3. otherwise => false 

        map<int,int> hashMap; 
        for(int& n : nums) hashMap[n]++; 
        for(auto& it : hashMap){
            if(it.second >= 2) return true; 
        }
        return false; 
    }
};