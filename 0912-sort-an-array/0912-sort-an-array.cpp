class Solution {
public:
    void mergeSort(vector<int>& arr, int left, int right){
        if(left >= right){
            return; 
        }

        int mid = (left + right) / 2; 
        mergeSort(arr, left, mid); 
        mergeSort(arr, mid + 1, right); 
        merge(arr, left, mid, right); 
    }

    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp(right - left + 1); 
        int i = left, j = mid + 1, k = 0; 
        while(i <= mid && j <= right) {
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++]; 
            } else{
                temp[k++] = arr[j++]; 
            }
        }

        while(i <= mid) temp[k++] = arr[i++]; 
        while(j <= right) temp[k++] = arr[j++]; 

        for(int i = 0; i < k; i++){
            arr[left+i] = temp[i]; 
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums; 
    }
};