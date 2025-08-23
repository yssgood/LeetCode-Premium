class Solution {
public:
    int partition(vector<int>& arr, int low, int high){
        // \U0001f525 ADD RANDOMIZATION: Choose random pivot instead of first element
        int randomIndex = low + rand() % (high - low + 1);
        swap(arr[low], arr[randomIndex]);  // Move random element to front
        
        int pivot = arr[low]; 
        int i = low + 1; 
        int j = high; 

        while (true) {
            while (i <= high && arr[i] <= pivot) {
                i++;
            }
        
            while (j >= low && arr[j] > pivot) {
                j--;
            }
        
            if (i >= j) break;
            
            swap(arr[i], arr[j]);
        }

        swap(arr[low], arr[j]);
        return j;    
    }
    
    void quickSort(vector<int>& arr, int low, int high){
        if(low < high){
            int pivotIndex = partition(arr, low, high); 
            quickSort(arr, low, pivotIndex - 1); 
            quickSort(arr, pivotIndex + 1, high); 
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));  // Initialize random seed
        quickSort(nums, 0, nums.size()-1);
        return nums; 
    }
};