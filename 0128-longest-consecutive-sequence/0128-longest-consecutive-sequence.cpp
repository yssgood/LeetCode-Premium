class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> hashMap; 
        for(int i = 0; i < nums.size(); i++){
            if(!hashMap.count(nums[i])) hashMap[nums[i]]++; 
        }

        for(auto& it : hashMap){
            if(hashMap.count(it.first-1)){
                hashMap[it.first] += hashMap[it.first - 1]; 
            }
        }

        int answer = 0; 
        for(auto& it : hashMap){
            answer = max(answer,it.second); 
        }

        return answer; 
    }
};


