/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        if(root == null) return root; 

        TreeNode left = null; 
        TreeNode right = null; 
        
        if(root.val > p.val){
            left = inorderSuccessor(root.left,p); 
            if(left != null) return left;
            return root; 
        }
        if(root.val <= p.val){
            right = inorderSuccessor(root.right,p); 
        }
        return right; 
    }
}