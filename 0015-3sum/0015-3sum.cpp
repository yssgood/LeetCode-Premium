class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer; 
        set<vector<int>> set; 
        sort(nums.begin(), nums.end()); 
        
        for(int i = 0; i < nums.size() - 2; i++){
            int start = i + 1;  
            int end = nums.size()-1; 
            while(start < end){
                int res = nums[i] + nums[start] + nums[end];
                if(res == 0){
                    //answer.push_back({nums[i], nums[start], nums[end]}); 
                    set.insert({nums[i], nums[start], nums[end]});
                    start++; 
                    end--;
                    //break; 
                }

                if(res > 0) end--; 
                if(res < 0) start++; 


            }
        }
        for(auto& it : set){
            answer.push_back(it); 
        }
        return answer; 
    }
};