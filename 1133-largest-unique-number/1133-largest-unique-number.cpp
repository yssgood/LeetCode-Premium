class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int answer = -1; 
        map<int,int> hashMap;
        for(int i = 0; i < nums.size(); i++){
            hashMap[nums[i]]++; 
        }
        for(auto& it : hashMap){
            if(it.second == 1) answer = max(answer, it.first); 
        }
        return answer; 
    }
};