class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        //smaller 은 인덱스로 커버하고 
        //between 
        //9 12 5 10 14 3 10 
        //9 5 3 10 14 12 10
        //9 5 3 10 10 12 14

        //-3 4 3 2 
        //-3 4 3 2 
        //-3 2 3 4 
        //-3 2 0 0

        vector<int> answer(nums.size(),0); 
        int index = 0; 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < pivot){
                answer[index++] = nums[i]; 
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == pivot){
                answer[index++] = nums[i]; 
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > pivot){
                answer [index++] = nums[i]; 
            }
        }
        return answer; 
    }
};