class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;  // Added !root check
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);  // Changed helper to lowestCommonAncestor
        TreeNode* right = lowestCommonAncestor(root->right, p, q); // Changed helper to lowestCommonAncestor

        if(left && right) return root;  // Both found → root is LCA
        if(left && !right) return left; 
        if(!left && right) return right; 

        return nullptr;  // Changed from root to nullptr
    }

    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return nullptr; 

        if(root == p || root == q){
            return root; 
        }

        TreeNode* left = helper(root->left, p, q); 
        TreeNode* right = helper(root->right, p, q); 

        if(left && right) return root;  // Added: both found → root is LCA
        if(left != nullptr){
            return left; 
        } 
        if(right != nullptr){
            return right; 
        }

        return nullptr; 
    }
};