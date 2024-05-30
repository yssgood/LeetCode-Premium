class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q; 
        q.push(start); 
        vector<bool> visited(arr.size(), false); 
        visited[start] = true; 

        while(!q.empty()){
            int size = q.size(); 

            for(int i = 0; i < size; i++){
                int curr = q.front(); 
                q.pop(); 


                if(arr[curr] == 0){
                    return true; 
                }


                int plusJump = curr + arr[curr]; 
                int minusJump = curr - arr[curr]; 


                if(plusJump < arr.size() && !visited[plusJump]){
                    q.push(plusJump); 
                    visited[plusJump] = true; 
                }

                if(minusJump >= 0 && !visited[minusJump]){
                    q.push(minusJump);
                    visited[minusJump] = true; 
                }
            }
        }

        return false; 
    }
};