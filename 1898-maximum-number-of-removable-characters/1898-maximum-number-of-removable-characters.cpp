class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        
        int answer = 0; 
        int left = 0, right = removable.size()-1; 
        string tmp = s; 
        while(left <= right){
            int mid = (right + left) / 2; 
            int start = 0; 
            for(int i = 0; i <= mid; i++){
                s[removable[i]] = '!'; 
            }
            
            for(int i = 0; i < s.length(); i++){
                if(s[i] == p[start]){
                    start++; 
                    if(start >= p.length()){
                        break; 
                    }
                }
            }

            s = tmp; 

            if(start >= p.length()){
                answer = max(answer, mid + 1); 
                left = mid + 1; 
            } else{
                right = mid -1; 
            }
        }

        return answer; 
    }
};