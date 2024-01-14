class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int answer = 0; 
        map<int,int> hashMap; 
        
        for(int n : nums){
            if(!hashMap.count(n)) hashMap[n]++; 
        }

        for(auto& it : hashMap){
            if(hashMap.count(it.first - 1)){
                hashMap[it.first]+=hashMap[it.first-1]; 
            }
        }

        for(auto& it : hashMap){
            answer = max(answer, it.second); 
        }

        
        
        return answer; 
    }
};