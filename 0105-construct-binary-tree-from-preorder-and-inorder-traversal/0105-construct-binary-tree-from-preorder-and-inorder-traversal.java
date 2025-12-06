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
    Map<Integer,Integer> hashMap = new HashMap<>(); 
    int index = 0; 
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        
        for(int i = 0; i < inorder.length; i++){
            hashMap.put(inorder[i], i); 
        }
        return buildTree(preorder,inorder,0,inorder.length-1); 
    }

    public TreeNode buildTree(int[] preorder, int[] inorder, int left, int right){
        if(left > right){
            return null; 
        }

        
        int rootIndex = hashMap.get(preorder[index]); 
        TreeNode root = new TreeNode(preorder[index++]); 

        TreeNode leftTree = buildTree(preorder, inorder, left, rootIndex-1); 
        TreeNode rightTree = buildTree(preorder, inorder, rootIndex + 1, right); 

        root.left = leftTree;  
        root.right = rightTree; 

        return root; 
    }
}