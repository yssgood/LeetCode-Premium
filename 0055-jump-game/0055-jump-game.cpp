class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> visited(nums.size(), false); 
        queue<int> q; 
        q.push(0);  

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                int curr = q.front(); 
                q.pop(); 

                if(curr >= nums.size()-1) return true; 

                for(int i = 1; i <= nums[curr]; i++){
                    int nCurr = curr + i; 

                    if(nCurr >= nums.size()-1) return true; 

                    if(!visited[nCurr]){
                        visited[nCurr] = true; 
                        q.push({nCurr}); 
                    }
                }
            }
        }
        return false; 
    }
};