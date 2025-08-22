/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //our idea, decrease targetSum by its root 
    //if we reach to correct leaf, what will happen to targetSum? 
    //we need to try this both to left and right
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false; 

        if(root->left == nullptr && root->right == nullptr){
            if(root->val == targetSum) return true; 
            return false; 
        }

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val); 
    }
};