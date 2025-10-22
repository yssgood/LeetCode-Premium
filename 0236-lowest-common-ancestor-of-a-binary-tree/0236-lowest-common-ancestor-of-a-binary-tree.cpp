/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root; 
        TreeNode* left = helper(root->left, p, q); 
        TreeNode* right = helper(root->right, p, q); 

        if(!left && !right) return nullptr;
        if(left && !right) return left; 
        if(!left && right) return right; 

        return root; 
    }

    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return nullptr; 

        if(root == p || root == q){
            return root; 
        }

        TreeNode* left = helper(root->left, p, q); 
        TreeNode* right = helper(root->right, p, q); 

        if(left != nullptr){
            return left; 
        } 
        if(right != nullptr){
            return right; 
        }

        return nullptr; 
    }
};