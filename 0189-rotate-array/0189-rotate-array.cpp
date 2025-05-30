class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //7 6 5 4 3 2 1 
        //5 6 7 1 2 3 4 
        k = k % (nums.size()); 
        reverse(nums.begin(), nums.end()); 
        reverse(nums.begin(),nums.begin() + k); 
        reverse(nums.begin()+k,nums.end()); 
    }
};