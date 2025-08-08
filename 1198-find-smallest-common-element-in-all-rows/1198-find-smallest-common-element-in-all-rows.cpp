class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int n = mat.size(); 
        int m = mat[0].size(); 

        for(int i = 0; i < m; i++){
            int candidate = mat[0][i]; 
            bool found = true;  

            for(int i = 1; i < n; i++){
                if(!binarySearch(candidate, mat[i])){
                    found = false; 
                }
            }

            if(found){
                return candidate; 
            }
        }

        return -1; 
    }

    bool binarySearch(int target, vector<int>& mat){
        int left = 0; 
        int right = mat.size()-1; 
        while(left <= right){
            int mid = left + (right - left) / 2; 
            if(mat[mid] == target){
                return true; 
            }

            if(mat[mid] < target){
                left = mid + 1; 
            } else{
                right = mid - 1; 
            }
        }

        return false; 
    }
};