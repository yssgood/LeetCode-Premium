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
    int answer = 0; 
    public int sumNumbers(TreeNode root) {
        if(root.left == null && root.right == null) return root.val; 
        sumNumbersHelper(root.left, root.val); 
        sumNumbersHelper(root.right, root.val); 
        return answer; 
    }

    public void sumNumbersHelper(TreeNode root, int val){
        if(root == null) return; 

        val = val * 10 + (root.val); 
        sumNumbersHelper(root.left,val); 
        sumNumbersHelper(root.right,val);

        if(root.left == null && root.right == null){
            answer += val; 
        }
    }
}