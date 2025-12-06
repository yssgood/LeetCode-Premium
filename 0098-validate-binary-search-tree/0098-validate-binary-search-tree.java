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
    public boolean isValidBST(TreeNode root) {
        if(root.left == null && root.right == null) return true; 
        return isValidBSTHelper(root, Long.MAX_VALUE, Long.MIN_VALUE); 
    }

    public boolean isValidBSTHelper(TreeNode root, long min_value, long max_value){
        if(root == null) return true; 

        if(root.val >= min_value || root.val <= max_value){
            return false; 
        }

        boolean left = isValidBSTHelper(root.left, Math.min(min_value, root.val), max_value); 
        boolean right = isValidBSTHelper(root.right, min_value, Math.max(max_value, root.val)); 

        return left && right; 
    }
}