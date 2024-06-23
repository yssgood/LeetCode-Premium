class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0; 
        int answer = 0; 
        unordered_map<int,int> hashMap; 
        hashMap[0] = 1; 
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i]; 
            if(hashMap.count(sum - k)){
                answer += hashMap[sum - k]; 
            }
            hashMap[sum]++; 
        }
        return answer; 
    }
};

/*
since it deals with negative number, In sliding window, 
you would increment left pointer whenever, curr_sum>k. But since number involves negative number, maybe with previous pointer, 
gaint that curr_sum could have been less than k or equal to k. Try once dry running on some code negative value, you would get the answer.

*/