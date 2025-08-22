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
    //when the problems' answer can appear anywhere from the subroot, 
    //it is better to define helper function and use main function to change the root location 
    bool isSubtreeHelper(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot){
            return true; 
        }

        if(!root || !subRoot){
            return false; 
        }

        if(root->val != subRoot->val){
            return false; 
        }

        return isSubtreeHelper(root->left,subRoot->left) && isSubtreeHelper(root->right, subRoot->right); 
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false; 

        if(isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)){
            return true; 
        }

        return isSubtreeHelper(root, subRoot) || isSubtreeHelper(root->left, subRoot) || isSubtreeHelper(root->right, subRoot); 
    }
};