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
    int currNum = 0; 
    int result = 0; 
    public int sumNumbers(TreeNode root) {
        dfs(root); 
        return result; 
    }

    public void dfs(TreeNode root){
        if(root == null) return; 
        currNum = currNum * 10 + root.val; 
        if(root.left ==  null && root.right == null){
            result += currNum; 
            currNum /= 10;
            return;
        }

        dfs(root.left); 
        dfs(root.right); 
        currNum /= 10; 
    }
}