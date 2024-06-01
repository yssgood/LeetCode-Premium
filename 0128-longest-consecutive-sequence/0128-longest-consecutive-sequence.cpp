class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hashMap; 
        for(int n : nums){
            hashMap[n]++; 
        }
        int answer = 0; 
        for(pair<int,int> it : hashMap){
            if(!hashMap.count(it.first - 1)){
                int longest_streak = 1; 
                int curr = it.first; 
                while(hashMap.count(curr + 1)){
                    longest_streak++; 
                    curr = curr + 1; 
                }

                answer = max(answer, longest_streak); 
            }
        }
        return answer; 
    }
};