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
    int getHeight(TreeNode* root) {
        if(!root){
            return 0; 
        }

        int left = getHeight(root->left); 
        int right = getHeight(root->right); 
        return max(left,right) + 1; 
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true; 

        //changing root part 
        if(!isBalanced(root->left) || !isBalanced(root->right)){
            return false; 
        } 

        //calculating part 
        int left = getHeight(root->left); 
        int right = getHeight(root->right); 


        return abs(right - left) <= 1; 
    }
};