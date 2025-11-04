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
    public TreeNode[] splitBST(TreeNode root, int target) {
        if(root == null) return new TreeNode[]{null,null}; 
        if(root.val > target){
            TreeNode[] split = splitBST(root.left, target); 
            root.left = split[1]; 
            return new TreeNode[]{split[0], root}; 
        } else{
            TreeNode[] split = splitBST(root.right, target); 
            root.right = split[0]; 
            return new TreeNode[]{root, split[1]}; 
        }
    }
}