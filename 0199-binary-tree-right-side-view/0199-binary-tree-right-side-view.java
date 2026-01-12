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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> answer = new ArrayList<>();
        if(root == null) return answer; 
        Queue<TreeNode> q = new LinkedList<>(); 
        q.add(root); 
        while(!q.isEmpty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode first = q.poll(); 
                if(i == size-1){
                    answer.add(first.val); 
                }

                if(first.left != null) q.add(first.left); 
                if(first.right != null) q.add(first.right); 
            }
        }
        return answer; 
    }
}