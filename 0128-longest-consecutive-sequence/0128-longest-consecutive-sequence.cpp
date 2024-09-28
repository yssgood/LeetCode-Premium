class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hashMap; 
        for(int n : nums) hashMap[n]++; 

        int answer = 0; 
        for(int n : nums){
            int curr = n; 
            
            if(!hashMap.count(curr-1)){
                int streak = 0; 
                while(hashMap.count(curr) && hashMap[curr] > 0){
                    streak++; 
                    hashMap[curr]--;
                    curr++; 
                }
                answer = max(answer, streak) ; 
            }
        }
        return answer; 
    }
};