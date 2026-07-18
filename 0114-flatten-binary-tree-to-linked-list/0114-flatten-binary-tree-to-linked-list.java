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
    public void flatten(TreeNode root) {
        if(root == null) return; 
        List<TreeNode> preOrder = new ArrayList<>(); 
        preOrderHelper(root, preOrder); 

        TreeNode curr = root; 
        for(int i = 1; i < preOrder.size(); i++){
            curr.left = null; 
            curr.right = preOrder.get(i); 
            curr = curr.right; 
        }
    }
    public void preOrderHelper(TreeNode root, List<TreeNode> preOrder){
        if(root == null) return; 

        preOrder.add(root); 
        preOrderHelper(root.left, preOrder); 
        preOrderHelper(root.right, preOrder); 
    }

}