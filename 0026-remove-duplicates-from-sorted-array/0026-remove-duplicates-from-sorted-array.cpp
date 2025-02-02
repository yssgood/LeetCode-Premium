class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> hashSet; 
        int index = 0; 
        for(int i = 0; i < nums.size(); i++){
            if(!hashSet.count(nums[i])){
                nums[index++] = nums[i]; 
            }
            hashSet.insert(nums[i]); 
        }
        return index; 
    }
};