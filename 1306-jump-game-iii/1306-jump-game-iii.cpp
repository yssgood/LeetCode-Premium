class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q; 
        q.push(start); 
        vector<bool> visited(arr.size(),false); 
        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                int curr = q.front(); 
                q.pop(); 

                int nX = curr + arr[curr]; 
                int nY = curr - arr[curr]; 

                if(nX < arr.size() && !visited[nX]){
                    if(arr[nX] == 0) return true; 
                    visited[nX] = true; 
                    q.push(nX); 
                }

                if(nY >= 0 && !visited[nY]){
                    if(arr[nY] == 0) return true; 
                    visited[nY] = true;
                    q.push(nY); 
                }
            }
        }
        return false; 
    }
};