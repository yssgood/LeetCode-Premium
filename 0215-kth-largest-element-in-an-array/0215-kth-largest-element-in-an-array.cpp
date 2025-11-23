class Solution {
public:
    int partition(vector<int>& nums, int left, int right){
        //int pivotVal = nums[left];
        int randomIndex = left + rand() % (right - left + 1); 
        swap(nums[left], nums[randomIndex]); 
        int pivotVal = nums[left]; 
        int i = left+1;
        int j = right;
        
        while (true){
            while (i <= right && nums[i] <= pivotVal){
                i++;
            }
            
            while (j >= left && nums[j] > pivotVal){
                j--;
            }
            
            if (j <= i){
                break;
            }
            swap(nums[i],nums[j]);
        }
        swap(nums[left],nums[j]);
        return j;
    }
    
    

    int quickSelect(vector<int>& nums, int left, int right, int targetIndex){
        if (left == right){
            return nums[left];
        }
        
        int ourIndex = partition(nums, left, right);
        
        if (ourIndex == targetIndex){
            return nums[ourIndex];
        }
        
        if (ourIndex > targetIndex){
            return quickSelect(nums,left,ourIndex-1,targetIndex);
        }
        
        
        return quickSelect(nums,ourIndex+1,right,targetIndex);
    }
    
    
    
    int findKthLargest(vector<int>& nums, int k) {
        //quickSelect(nums, left, right, targetIndex) 
        int targetIndex = nums.size()-k;
        return quickSelect(nums,0,nums.size()-1,targetIndex);
    }
};