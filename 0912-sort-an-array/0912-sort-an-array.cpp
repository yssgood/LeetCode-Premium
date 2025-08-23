class Solution {
public:
    void mergeSort(vector<int>& nums, int left, int right){
        if(left >= right){
            return; 
        }

        int mid = (right + left) / 2; 
        mergeSort(nums, left, mid); 
        mergeSort(nums, mid + 1, right); 
        merge(nums,left, mid,right); 
    }
    void merge(vector<int>& nums, int left, int mid, int right){
        vector<int> tmp(right - left + 1); 
        int i = left; 
        int j = mid + 1; 
        int k = 0; 
        while(i <= mid && j <= right){
            if(nums[i] <= nums[j]){
                tmp[k] = nums[i]; 
                k++; 
                i++; 
            } else{
                tmp[k] = nums[j]; 
                k++; 
                j++; 
            }
        }

        while(i <= mid) tmp[k++] = nums[i++]; 
        while(j <= mid) tmp[k++] = nums[j++]; 

        for(int i = 0; i < k; i++){
            nums[left + i] = tmp[i]; 
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums; 
    }
};