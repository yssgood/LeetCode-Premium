class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1}; 
        vector<int> answer = {-1,-1}; 
        int left = 0, right = nums.size()-1; 
        while(left <= right){
            int mid = (right + left) / 2; 
            if(nums[mid] == target){
                answer[0] = mid; 
                right = mid - 1; 
            } else if(nums[mid] < target){
                left = mid + 1; 
            } else{
                right = mid - 1; 
            }
        }
        
        // if(nums[left] != target){
        //     return {-1,-1}; 
        // } else{
        //     answer[0] = left; 
        // }

        left = 0; 
        right = nums.size()-1; 

        while(left <= right){
            int mid = (right + left) / 2; 
            if(nums[mid] == target){
                answer[1] = mid; 
                left = mid + 1; 
            } else if(nums[mid] < target){
                left = mid + 1; 
            } else{
                right = mid - 1; 
            }
        }

        return answer; 
    }
};


// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         vector<int> answer{-1,-1}; 
//         int start = 0; 
//         int end = nums.size()-1; 
        
//         while(start <= end){
//             int mid = start + (end-start)/2; 
            
//             if(nums[mid] == target){
//                 answer[0] = mid; 
//                 end = mid-1; 
//             }
            
//             else if (nums[mid] < target) start = mid+1;
//             else end = mid-1; 
            
//         }
        
//         start = 0, end = nums.size()-1; 
        
//         while(start <= end){
//             int mid = start + (end-start)/2; 
            
//             if(nums[mid] == target){
//                 answer[1] = mid; 
//                 start = mid+1; 
//             }
//             else if (nums[mid] < target) start = mid+1;
//             else end = mid-1;
//         }
        
        
        
//         return answer; 
//     }
// };
