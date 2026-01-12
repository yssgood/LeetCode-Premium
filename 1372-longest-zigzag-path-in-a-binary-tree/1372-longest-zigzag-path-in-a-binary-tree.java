class Solution {
    int maxLength = 0; 
    
    public int longestZigZag(TreeNode root) {
        if (root == null) return 0; 
        dfs(root, 0, 0); // left
        dfs(root, 1, 0); // right
        return maxLength; 
    }
    
    public void dfs(TreeNode root, int dir, int length) {
        if (root == null) return; 
        
        maxLength = Math.max(maxLength, length);
        
        if (dir == 0) { // 왼쪽으로 가야 함
            dfs(root.left, 1, length + 1);  // zigzag 계속
            dfs(root.right, 0, 1);          // 새로 시작
        }
        if (dir == 1) { // 오른쪽으로 가야 함
            dfs(root.right, 0, length + 1); // zigzag 계속
            dfs(root.left, 1, 1);           // 새로 시작
        }
    }
}