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
    List<TreeNode> arrList = new ArrayList<>(); 
    public void flatten(TreeNode root) {
        if(root == null) return; 
        dfs(root); 
        root.left = null; 
        for(int i = 1; i < arrList.size(); i++){
            TreeNode curr = arrList.get(i); 
            curr.left = null; 
            root.right = curr; 
            root = root.right; 
        }
    }

    public void dfs(TreeNode root){
        if(root == null) return; 
        arrList.add(root); 
        dfs(root.left); 
        dfs(root.right); 
    }
}