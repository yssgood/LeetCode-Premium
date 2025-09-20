class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> answer; 
        map<int,int> hashMap; 
        for(int n : nums) hashMap[n]++; 
        for(int i = 1; i <= nums.size(); i++){
            if(!hashMap.count(i)){
                answer.push_back(i); 
            }
        }
        return answer; 
    }
};