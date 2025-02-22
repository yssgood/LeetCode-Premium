class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        if(arr.size() <= 1) return 1; 
        map<int,int> hashMap; 
        int max_ =  1; 
        for(int i = 0; i < arr.size(); i++){
            int target = arr[i] - difference; 
            if(hashMap.count(target)){
                hashMap[arr[i]] = max(hashMap[arr[i]], 1 + hashMap[target]); 
                max_ = max(max_, hashMap[arr[i]]); 
            } else{
                hashMap[arr[i]] = max(1,hashMap[arr[i]]); 
            }
            //max_ = max(max_, hashMap[arr[i]]); 
        }

        return max_; 
    }
};