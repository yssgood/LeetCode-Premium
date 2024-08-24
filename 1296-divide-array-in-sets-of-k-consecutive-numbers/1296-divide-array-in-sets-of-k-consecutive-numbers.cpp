class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> hashMap; 
        for(int n : nums) hashMap[n]++; 
        int groups = 0; 
        sort(nums.begin(),nums.end()); 
        for(int i = 0; i < nums.size(); i++){
            if(hashMap[nums[i]] <= 0) continue; 
            int currNum = nums[i]; 
            int streak = 1; 
            hashMap[nums[i]]--; 
            while(hashMap[currNum + 1] > 0 && streak < k){
                hashMap[currNum + 1]--; 
                streak++;
                currNum++; 
            }

            //cout << nums[i] << ' ' << streak << endl; 

            if(streak == k){
                groups++; 
            }
        }

        return (groups * k) == nums.size() ? true : false;  
    }
};