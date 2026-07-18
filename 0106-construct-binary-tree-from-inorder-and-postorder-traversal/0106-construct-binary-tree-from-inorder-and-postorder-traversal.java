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
    int index = 0; 
    Map<Integer,Integer> hashMap = new HashMap<>(); 
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        index = postorder.length-1;  
        for(int i = 0; i < inorder.length; i++){
            hashMap.put(inorder[i], i); 
        }
        return buildTreeHelper(inorder, postorder, 0, inorder.length-1); 
    }

    public TreeNode buildTreeHelper(int[] inorder, int[] postorder, int left, int right){
        if(left > right){
            return null; 
        }

        int curr = postorder[index--]; 
        TreeNode root = new TreeNode(curr);  

        TreeNode rightTree = buildTreeHelper(inorder, postorder, hashMap.get(curr) + 1, right); 
        TreeNode leftTree = buildTreeHelper(inorder, postorder, left, hashMap.get(curr) - 1); 

        root.right = rightTree; 
        root.left = leftTree; 

        return root; 
    }
}