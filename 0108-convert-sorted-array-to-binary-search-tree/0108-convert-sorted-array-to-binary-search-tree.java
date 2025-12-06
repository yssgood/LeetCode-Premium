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
    public TreeNode sortedArrayToBST(int[] nums) {
        int middleIndex = nums.length / 2; 
        TreeNode root = new TreeNode(nums[middleIndex]); 
        TreeNode leftNode = buildTree(root,0,middleIndex-1,nums); 
        TreeNode rightNode = buildTree(root,middleIndex+1,nums.length-1,nums); 

        root.left = leftNode; 
        root.right = rightNode; 
        return root; 
    }

    public TreeNode buildTree(TreeNode root, int left, int right, int[] nums){
        if(left > right) return null; 

        int middleIndex = left + (right - left) / 2;
        TreeNode node = new TreeNode(nums[middleIndex]);
        TreeNode leftNode = buildTree(node,left,middleIndex-1,nums); 
        TreeNode rightNode = buildTree(node,middleIndex+1,right,nums); 

        node.left = leftNode; 
        node.right = rightNode; 
        return node; 
    }
}