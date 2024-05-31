class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //for 
        //...for
        //.......if(0) for ...
        //................for......

        //row map 
        //col map 

        //rowmap => 1 
        //colmap => 1 

        //{1,1} 
        //{0,1} / {1,0} / {1,2}
        //{2,0} / {2,1} 


        map<int,bool> rowMap, colMap; 
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    rowMap[i] = true; 
                    colMap[j] = true; 
                }
            }
        }

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(rowMap.count(i) || colMap.count(j)){
                    matrix[i][j] = 0; 
                }
            }
        }
    }
};