class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true; 
        vector<bool> visited(nums.size(), false); 
        queue<int> q; 
        q.push(0); 
        visited[0] = true; 

        while(!q.empty()){
            int size = q.size(); 

            for(int i = 0; i < size; i++){
                int curr = q.front();
                q.pop(); 

                
                for(int i = 1; i <= nums[curr]; i++){
                    int next = curr + i; 
                    if(next >= nums.size() || next != nums.size() -1 && nums[next] == 0 || visited[next]) continue; 

                    if(next == nums.size() -1) return true; 
                    //cout << next << ' '; 
                    q.push(next); 
                    visited[next] = true; 
                }
            }
        }
        return false; 
    }
};

// class Solution {
// public:
//     bool visited[10001]; 
//     bool canJump(vector<int>& nums) {
//         queue<int> q; 
//         memset(visited, false, sizeof(visited)); 
//         q.push(0); 
//         visited[0] = true; 
        
//         while(!q.empty()){
//             int size = q.size();
//             for(int i = 0; i < size; i++){
//                 int index = q.front(); 
//                 q.pop(); 

//                 if(index >= nums.size()-1){
//                     return true; 
//                 }

//                 for(int j = 1; j <= nums[index]; j++){
//                     int new_index = index + j; 

//                     if(new_index >= nums.size() || new_index != nums.size()-1 && nums[new_index] == 0 || visited[new_index]) continue; 
//                     if(new_index == nums.size() -1) return true; 
//                     visited[new_index] = true; 
//                     q.push({new_index}); 
//                 }
//             }
//         }

//         return false; 
//     }
// };