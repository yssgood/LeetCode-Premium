class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        unordered_map<int,int> rowMap, colMap; 
        for(int i = 0; i < picture.size(); i++){
            for(int j = 0; j < picture[i].size(); j++){
                if(picture[i][j] == 'B'){
                    rowMap[i]++;
                    colMap[j]++; 
                }
            }
        }
        int answer = 0; 
        for(int i = 0; i < picture.size(); i++){
            for(int j = 0; j < picture[i].size(); j++){
                if(picture[i][j] == 'B' && rowMap[i] == 1 && colMap[j] == 1){
                    answer++; 
                }
            }
        }
        return answer; 
    }
};