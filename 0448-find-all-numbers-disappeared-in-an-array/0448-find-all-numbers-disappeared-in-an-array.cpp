class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> answer; 
        
        for(int i = 0; i < nums.size(); ++i){
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]); 
        }
        
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] > 0){
                answer.push_back(i+1);
            }
        }

        return answer; 
    }
};





        //4 3 2 7 8 2 3 1
        //1 2 2 3 3 4 7 8
