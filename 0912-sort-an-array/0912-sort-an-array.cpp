class Solution {
public:
    void quickSort(vector<int>& nums, int left, int right){
        if(left >= right) return; //when no more to divide 
        int pivotIndex = partition(nums,left,right); 
        quickSort(nums,left,pivotIndex-1); 
        quickSort(nums,pivotIndex+1,right); 
    }
    int partition(vector<int>& nums, int left, int right){
        //int pivot = nums[left]; 
        int randomIndex = left + rand() % (right - left + 1);
        swap(nums[left], nums[randomIndex]);  // Move random element to front
        int pivot = nums[left]; 
        int i = left + 1; 
        int j = right; 

        while(true){
            while(i <= right && nums[i] <= pivot) i++; //allow duplicates to the left side 
            while(j >= left && nums[j] > pivot) j--; //strictly larger elements on the right side

            if(i >= j) break; 
            
            swap(nums[i],nums[j]); 
        }
        //at the end, all of the elements in the left side are smaller than the pivot 
        //all of the elements in the right side are biger than the pivot 
        //j is the index where my pivot should be 

        swap(nums[left],nums[j]); 
        //swap(pivot,nums[j]) will only try to swap the values, we need to change the location!
        return j; 
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1); 
        return nums; 
    }
};