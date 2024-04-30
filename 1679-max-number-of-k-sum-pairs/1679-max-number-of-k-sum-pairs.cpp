class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> hashMap; 
        int answer = 0; 
        for(int n : nums){
            if(hashMap.count(k - n)){
                answer++; 
                if(--hashMap[k-n] <= 0) hashMap.erase(k - n); 
            } else{
                hashMap[n]++; 
            }
        }
        return answer; 
    }
};