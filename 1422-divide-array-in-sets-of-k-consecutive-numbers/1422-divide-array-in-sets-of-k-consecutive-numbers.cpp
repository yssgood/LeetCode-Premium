class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> hashMap; 
        for(int n : nums) hashMap[n]++; 
        sort(nums.begin(), nums.end()); 
        for(int i = 0; i < nums.size(); i++){
            int n = nums[i]; 
            if(hashMap[n] > 0){
                for(int next = n; next < n + k; next++){
                    if(!hashMap.count(next) || hashMap[next] < 1){
                        //cout << next << ' ' << hashMap[next] << endl; 
                        return false; 
                    }
                hashMap[next]--; 
                }
            }
        }

        return true; 
    }
};