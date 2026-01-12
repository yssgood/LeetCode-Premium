class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) return null; 
        
        if (root.val == key) {
            if (root.right == null) return root.left;
            if (root.left == null) return root.right;
            
            // 자식 2개: successor 값 복사 후 successor 삭제
            TreeNode minNode = root.right;
            while (minNode.left != null) {
                minNode = minNode.left;
            }
            root.val = minNode.val;
            root.right = deleteNode(root.right, minNode.val);
            return root;
        }

        if (key < root.val) {
            root.left = deleteNode(root.left, key);
        } else {
            root.right = deleteNode(root.right, key);
        }

        return root; 
    }
}