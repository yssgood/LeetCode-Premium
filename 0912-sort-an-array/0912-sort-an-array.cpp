class Solution {
public:
    int partition(vector<int>& arr, int low, int high){
        int randomIndex = low + rand() % (high - low + 1);
        swap(arr[low], arr[randomIndex]);  // Move random element to front
        int pivot = arr[low]; 
        int i = low + 1; 
        int j = high; 

        while (true) {
            // Move i right: find element that should be on right side (> pivot)
            while (i <= high && arr[i] <= pivot) {
                i++;
            }
        
            // Move j left: find element that should be on left side (<= pivot)
            while (j >= low && arr[j] > pivot) {
                j--;
            }
        
            // If pointers crossed, partitioning is done
            if (i >= j) break;
            
            // Swap the misplaced elements
            swap(arr[i], arr[j]);
        }

        // Place pivot in its correct final position
        swap(arr[low], arr[j]);
        return j;    
    }
    void quickSort(vector<int>& arr, int low, int high){
        if(low >= high) return; 
        
        int pivotIndex = partition(arr, low, high); 
        quickSort(arr, low, pivotIndex - 1); 
        quickSort(arr, pivotIndex + 1, high); 
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums; 
    }
};