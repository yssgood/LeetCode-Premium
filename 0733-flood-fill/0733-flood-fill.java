class Solution {
    public void dfs(int[][] image, int sr, int sc, int color, int keepColor){
        if(sr < 0 || sr >= image.length || sc < 0 || sc >= image[0].length || image[sr][sc] != keepColor) return; 

        image[sr][sc] = color; 
        dfs(image,sr+1,sc,color,keepColor); 
        dfs(image,sr-1,sc,color,keepColor);
        dfs(image,sr,sc+1,color,keepColor); 
        dfs(image,sr,sc-1,color,keepColor); 
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        dfs(image,sr,sc,color,image[sr][sc]);
        return image; 
    }
}