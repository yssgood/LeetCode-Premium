class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) return null; 
        
        if (root.val == key) {
            // 자식 없거나 1개
            if (root.right == null) return root.left;
            if (root.left == null) return root.right;
            
            // 자식 2개: 왼쪽 서브트리를 오른쪽 최솟값 아래에 붙임
            TreeNode tmp = root.left; 
            TreeNode minNode = root.right;
            while (minNode.left != null) {
                minNode = minNode.left;
            }
            minNode.left = tmp;
            return root.right;
        }

        // BST 탐색
        if (key < root.val) {
            root.left = deleteNode(root.left, key);
        } else {
            root.right = deleteNode(root.right, key);
        }

        return root; 
    }
}