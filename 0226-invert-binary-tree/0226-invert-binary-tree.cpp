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
    //lets use post-order approach  
    //reach to left and right child firs  
    //then lets determine what to do at the root  
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr; 
        }

        TreeNode* left = invertTree(root->left); //left
        TreeNode* right = invertTree(root->right); //right 

        //what should i do at the root? 
        root->left = right; 
        root->right = left; 

        return root; 

    }
};