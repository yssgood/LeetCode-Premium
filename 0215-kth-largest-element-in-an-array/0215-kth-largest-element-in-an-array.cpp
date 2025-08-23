class Solution {
public:
    int quickSelect(vector<int>& nums, int left, int right, int k){
        if(left == right){
            return nums[left]; 
        }

        int pivotIndex = partition(nums, left, right); 
        if(pivotIndex == k){
            return nums[pivotIndex]; 
        }
        if(pivotIndex < k){
            return quickSelect(nums, pivotIndex + 1, right, k); 
        }
        return quickSelect(nums, left, pivotIndex-1, k); 
    }
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[left]; 
        int i = left + 1, j = right; 
        while(true){
            while(i <= right && nums[i] <= pivot) i++; 
            while(j >= left && nums[j] > pivot) j--; 
            if(i >= j) break; 
            swap(nums[i], nums[j]); 
        }
        swap(nums[left], nums[j]); 
        return j; 
    }
    int findKthLargest(vector<int>& nums, int k) {
        int targetIndex = nums.size() - k; 
        return quickSelect(nums,0,nums.size()-1,targetIndex);
    }
};