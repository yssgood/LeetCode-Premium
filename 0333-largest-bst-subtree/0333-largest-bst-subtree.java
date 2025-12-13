class Solution {
    int maxSize = 0;
    
    public int largestBSTSubtree(TreeNode root) {
        dfs(root);
        return maxSize;
    }
    
    public int dfs(TreeNode root) {
        if(root == null) return 0;
        
        // try current node as BST root
        int size = validBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
        
        if(size > 0) {
            maxSize = Math.max(maxSize, size);
        } else {
            // if invalid, check left and right subtrees
            dfs(root.left);
            dfs(root.right);
        }
        
        return size;
    }
    
    public int validBST(TreeNode root, long minValue, long maxValue) {
        if(root == null) return 0;
        
        if(root.val <= minValue || root.val >= maxValue) {
            return -1;
        }
        
        int leftSize = validBST(root.left, minValue, root.val);
        int rightSize = validBST(root.right, root.val, maxValue);
        
        if(leftSize >= 0 && rightSize >= 0) {
            return leftSize + rightSize + 1;
        }
        
        return -1;
    }
}