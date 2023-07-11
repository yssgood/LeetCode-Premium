class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        map<int,int> rowMap, colMap; 
        int answer = 0; 
        for(int i = 0; i < picture.size(); i++){
            for(int j = 0; j < picture[0].size(); j++){
                if(picture[i][j] == 'B'){
                    rowMap[i]++; 
                    colMap[j]++; 
                }
            }
        }

        for(int i = 0; i < picture.size(); i++){
            for(int j = 0; j < picture[0].size(); j++){
                if(picture[i][j] == 'B' && (rowMap[i] == 1) && (colMap[j] == 1)) answer++; 
            }
        }
        return answer; 
    }
};