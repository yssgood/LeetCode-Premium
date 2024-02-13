class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> visited(nums.size(),false); 
        queue<int> q; 
        q.push(0); 
        visited[0] = true; 

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                int first = q.front();
                q.pop(); 

                if(first == nums.size() - 1) return true; 

                int ele = nums[first]; 

                for(int j = 1; j <= ele; j++){
                    if(first + j < nums.size() && !visited[first+j]){
                        //cout << ele << ' ' <<  first + j << ' ' << nums[first+j] << endl; 
                        if(first + j == nums.size() - 1) return true; 
                        if(nums[first + j] != 0){
                            q.push(first + j); 
                            visited[first+j] = true; 
                        }
                    }
                }
            }
        }

        return false; 
    }
};