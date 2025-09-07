class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int startnum){
        if (sr >= image.size() || sr < 0){
            return;
        }
        if (sc >= image[sr].size() || sc < 0){
            return;
        }
        
        if (image[sr][sc] != startnum){
            return;
        }
        
        image[sr][sc] = color;
        dfs(image,sr+1,sc,color,startnum);
        dfs(image,sr-1,sc,color,startnum);
        dfs(image,sr,sc+1,color,startnum);
        dfs(image,sr,sc-1,color,startnum);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color){
            return image;
        }
        int startnum = image[sr][sc];
        dfs(image,sr,sc,color,startnum);
        return image;
        
    }
};