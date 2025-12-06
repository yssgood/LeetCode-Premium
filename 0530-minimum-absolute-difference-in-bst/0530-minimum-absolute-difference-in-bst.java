/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int min_ = Integer.MAX_VALUE; 
    TreeNode prev = null; 
    public int getMinimumDifference(TreeNode root) {
        if(root == null) return 0; 
        dfs(root); 
        return min_; 
    }
    public void dfs(TreeNode root){
        if(root == null) return; 
        dfs(root.left); 
        if(prev != null){
            min_ = Math.min(min_, Math.abs(root.val - prev.val)); 
        }

        prev = root; 
        dfs(root.right); 
    }
}