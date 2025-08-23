class Solution {
public:
    int partition(vector<int>& arr, int low, int high) {
        // Using leftmost element as pivot (can cause TLE!)
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
    
    int quickSelect(vector<int>& arr, int low, int high, int k) {
        if (low == high) {
            return arr[low];  // Base case: single element
        }
        
        int pivotIndex = partition(arr, low, high);
        
        if (pivotIndex == k) {
            return arr[pivotIndex];  // Found the k-th element!
        }
        else if (k < pivotIndex) {
            // Target is in left partition
            return quickSelect(arr, low, pivotIndex - 1, k);
        }
        else {
            // Target is in right partition  
            return quickSelect(arr, pivotIndex + 1, high, k);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        // No random seed needed since we're using deterministic pivot
        
        // Convert "k-th largest" to "index of k-th largest"
        // For k-th largest in 0-indexed array: targetIndex = n - k
        int n = nums.size();
        int targetIndex = n - k;
        
        return quickSelect(nums, 0, n - 1, targetIndex);
    }
};