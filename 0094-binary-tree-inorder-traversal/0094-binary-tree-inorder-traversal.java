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
    List<Integer> answer = new ArrayList<>(); 
    public List<Integer> inorderTraversal(TreeNode root) {
        if(root == null) return answer; 
        inorder(root);
        return answer; 
    }
    public void inorder(TreeNode root){
        if(root == null) return; 
        inorder(root.left);
        answer.add(root.val); 
        inorder(root.right); 
    }
}