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
            TreeNode[] leftTree = splitBST(root.left, target); 
            root.left = leftTree[1]; 
            return new TreeNode[]{leftTree[0], root}; 
        } else{
            TreeNode[] rightTree = splitBST(root.right, target); 
            root.right = rightTree[0]; 
            return new TreeNode[]{root, rightTree[1]}; 
        }
    }
}