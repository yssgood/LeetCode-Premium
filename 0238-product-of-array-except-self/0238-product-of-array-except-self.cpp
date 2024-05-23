class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size()+1,1);
        vector<int> suffix(nums.size()+1,1); 
        for(int i = 1; i <= nums.size(); i++){
            prefix[i] = prefix[i-1] * nums[i-1]; 
        }

        for(int i = nums.size()-1; i >= 0; i--){
            suffix[i] = suffix[i+1] * nums[i]; 
        }        

        vector<int> answer(nums.size(),0); 
        // for(int i = 1; i < prefix.size(); i++){
        //     cout << prefix[i] << ' '; 
        // }
        // cout << endl; 
        // for(int i = 0; i <= nums.size()-1; i++){
        //     cout << suffix[i] << ' '; 
        // }        

        for(int i = 0; i < nums.size(); i++){
            int pre = 1; 
            int suf = 1; 
            if(i-1 >= 0) pre = prefix[i + 1 -1]; 
            if(i + 1 < nums.size()) suf = suffix[i+1]; 

            answer[i] = pre * suf; 
        }
        return answer; 
    }
};