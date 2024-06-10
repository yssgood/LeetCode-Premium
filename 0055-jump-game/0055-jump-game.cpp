class Solution {
public:
    bool visited[10001]; 
    bool canJump(vector<int>& nums) {
        queue<int> q;
        q.push(0); 
        visited[0] = true; 


        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int curr_index = q.front();
                q.pop(); 

                if(curr_index == nums.size()-1) return true; 

                for(int i = 1; i <= nums[curr_index]; i++){
                    int new_index = curr_index + i; 

                    if(new_index == nums.size()-1) return true; 

                    if(new_index < nums.size() && nums[new_index] != 0 && !visited[new_index]){
                        q.push(new_index);
                        visited[new_index] = true; 
                    }
                }
            }
        }

        return false; 
    }
};