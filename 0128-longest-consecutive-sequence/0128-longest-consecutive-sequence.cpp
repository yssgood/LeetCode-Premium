class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0; 
        map<int,int> hashMap; 
        for(int n : nums) hashMap[n]++; 
        int answer = INT_MIN; 
        for(auto& it : hashMap){
            int n = it.first; 
            if(!hashMap.count(n-1)){
                int currStreak = 1; 
                int tmp = n;  
                while(hashMap.count(tmp + 1)){
                    tmp += 1; 
                    currStreak += 1; 
                }

                answer = max(answer, currStreak); 
            }

            
        }

        return answer; 
    }
};