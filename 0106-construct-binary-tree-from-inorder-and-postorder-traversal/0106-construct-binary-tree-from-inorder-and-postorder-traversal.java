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
    int index; 
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        for(int i = 0; i < inorder.length; i++){
            hashMap.put(inorder[i], i); 
        }
        index = postorder.length-1; 
        return buildTree(inorder, postorder, 0, postorder.length-1); 
    }

    public TreeNode buildTree(int[] inorder, int[] postorder, int left, int right){
        if(left > right || index < 0){
            return null; 
        }
        
        int rootPos = hashMap.get(postorder[index]); 
        TreeNode root = new TreeNode(postorder[index--]); 

        TreeNode rightTree = buildTree(inorder, postorder, rootPos+1, right); 
        TreeNode leftTree = buildTree(inorder, postorder, left, rootPos-1); 

        root.left = leftTree; 
        root.right = rightTree; 

        return root; 
    }
}