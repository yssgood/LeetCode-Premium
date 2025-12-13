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
    public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
        List<Integer> l1 = new ArrayList<>(); 
        List<Integer> l2 = new ArrayList<>(); 
        dfs(root1,l1);
        dfs(root2,l2); 
        int i = 0, j = l2.size()-1; 
        while(i < l1.size() && j >= 0){
            int sum = l1.get(i) + l2.get(j); 
            if(sum == target) return true; 
            if(sum < target) i++; 
            else j--; 
        }
        return false; 
    }
    public void dfs(TreeNode root, List<Integer> lst){
        if(root == null) return;
        dfs(root.left, lst); 
        lst.add(root.val);
        dfs(root.right, lst); 
    }
}