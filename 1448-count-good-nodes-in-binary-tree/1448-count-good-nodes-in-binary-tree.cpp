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
    void goodNodesHelper(int& count, TreeNode* root, int prev){
        if(!root) return; 
        if(root->val >= prev){
            count++; 
        } 
        goodNodesHelper(count, root->left, max(root->val,prev)); 
        goodNodesHelper(count, root->right, max(root->val,prev)); 
    }
    int goodNodes(TreeNode* root) {
        int count = 0; 
        goodNodesHelper(count, root, root->val);
        return count; 
    }
};