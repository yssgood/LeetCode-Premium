class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hashMap; 
        int answer = 0;  
        for(int i = 0; i < nums.size(); i++){
            hashMap[nums[i]]++; 
        }

        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i]; 
            if(!hashMap.count(curr -1)){
                int longestStreak = 1;
                while(hashMap.count(curr + 1)){
                    curr = curr + 1; 
                    longestStreak++;
                }
                answer = max(answer, longestStreak); 
            }
        }
        return answer; 
    }
};