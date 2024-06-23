class Solution {
public:

    bool isSub(string s, string& p, vector<int>& removable, int k){
        
        int pPoint = 0;
    
        for(int i = 0; i <= k; i++){
            s[removable[i]] = '-'; 
        }

        for(int i = 0; i < s.length(); i++){
            if(s[i] == p[pPoint]){
                pPoint++; 
            }

            if(pPoint >= p.length()) return true; 
        }

        return false; 
        
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0, right = removable.size()-1; 


        while(left <= right){
            int mid = (right + left) / 2; 
            
            //cout << mid << endl; 
            if(isSub(s,p,removable,mid)){
                
                left = mid + 1; 
            } else{
                right = mid -1;
            }
        }

        return left; 
    }
};