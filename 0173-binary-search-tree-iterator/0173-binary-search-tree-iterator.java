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
class BSTIterator {

    List<TreeNode> inOrder = new ArrayList<>(); 
    int index = 0; 

    public BSTIterator(TreeNode root) {
        helper(root,inOrder); 
    }
    
    public int next() {
        return inOrder.get(index++).val; 
    }
    
    public boolean hasNext() {
        return index < inOrder.size(); 
    }

    public void helper(TreeNode root, List<TreeNode> inOrder){
        if(root == null) return; 

        helper(root.left, inOrder); 
        inOrder.add(root); 
        helper(root.right, inOrder); 
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */