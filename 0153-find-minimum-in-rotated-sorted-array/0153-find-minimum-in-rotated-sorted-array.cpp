class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1; 
        while(left < right){
            //cout << right << ' ' << left << endl; 
            int mid = (right + left) / 2; 

            if(nums[mid] > nums[right]){
                left = mid + 1; 
            } else{
                right = mid; 
            }
        }

        return nums[left]; 
    }
};