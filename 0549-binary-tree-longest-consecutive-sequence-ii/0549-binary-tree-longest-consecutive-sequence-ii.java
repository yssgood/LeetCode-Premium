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
    int max_ = 0; 
    public int longestConsecutive(TreeNode root) {
        dfs(root); 
        return max_; 
    }
    public int[] dfs(TreeNode root){
        if(root == null) return new int[]{0,0}; 
        int[] left = dfs(root.left); 
        int[] right = dfs(root.right); 

        int inc = 1; 
        int dec = 1; 

        if(root.left != null){
            if(root.val - root.left.val == -1){
                //left[1]++; 
                inc = Math.max(inc, left[0] + 1); 
                
            }
            if(root.val - root.left.val == 1){
                //left[0]++; 
                dec = Math.max(dec, left[1] + 1); 
            }
        }

        if(root.right != null){
            if(root.val - root.right.val == -1){
                //right[1]++; 
                inc = Math.max(inc, right[0] + 1); 
            }
            if(root.val - root.right.val == 1){
                //right[0]++; 
                dec = Math.max(dec, right[1] + 1); 
            }
        }

        //max_ = Math.max(max_, Math.max(left[0] + right[1], left[1] + right[0])); 

        max_ = Math.max(max_, dec + inc - 1); 


        return new int[]{inc, dec}; 
    }
}