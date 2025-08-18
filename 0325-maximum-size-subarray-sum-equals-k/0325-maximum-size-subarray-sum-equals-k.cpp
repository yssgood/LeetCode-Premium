class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        long long max_ = 0; 
        map<long long,long long> hashMap; 
        
        hashMap[nums[0]] = 0; 
        for(int i = 1; i < nums.size(); i++){
            nums[i] = nums[i-1] + nums[i]; 
            if(!hashMap.count(nums[i])) hashMap[nums[i]] = i; 
        }
        
        for(int i = 0; i < nums.size(); i++){
            long long target = (long long)nums[i] - k; 
            if(nums[i] == k){
                max_ = max(max_, (long long)i - 0 + 1); 
            } else if(hashMap.count(target)){
                max_ = max(max_, (long long)i - (hashMap[target] + 1) + 1); 
            }
        }
        //1, 0, 5, 3, 6
        //1, 0, 5, 
        //-2 -1 2 1 
        //-2 -3 -1 0
        return max_; 
    }
};