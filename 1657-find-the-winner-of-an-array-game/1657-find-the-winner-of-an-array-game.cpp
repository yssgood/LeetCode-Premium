class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        queue<int> q; 
        int max_ele = INT_MIN;
        int curr_ele = arr[0];  
        for(int i = 1; i < arr.size(); i++){
            max_ele = max(max_ele, arr[i]); 
            q.push(arr[i]); 
        }
        
        int win = 0; 
        while(!q.empty()){
            int fight = q.front(); 
            
            if(curr_ele > fight){
                q.pop();
                q.push(fight); 
                //curr_ele = fight; 
                win++; 
            }
            else{
                q.pop(); 
                q.push(curr_ele); 
                curr_ele = fight; 
                win = 1; 
            }


            if(win == k || curr_ele == max_ele){
                return curr_ele; 
            }
        }

        return -1; 
    }
};