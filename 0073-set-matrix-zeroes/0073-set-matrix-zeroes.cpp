class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int,int> rowMap, colMap; 
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    rowMap[i]++; 
                    colMap[j]++; 
                }
            }
        }

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(rowMap.count(i) || colMap.count(j)){
                    matrix[i][j] = 0; 
                }
            }
        }
    }
};