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
    void flatten(TreeNode* root) {
        if(!root) return; 
        vector<int> preOrder; 
        dfs(root,preOrder); 

        TreeNode* curr = root; 
        for(int i = 1; i < preOrder.size(); i++){
            curr->left = nullptr; 
            curr->right = new TreeNode(preOrder[i]);
            curr = curr->right; 
        }
        root->left = nullptr; 
    }

    void dfs(TreeNode* root, vector<int>& preOrder){
        if(!root) return; 
        preOrder.push_back(root->val); 
        dfs(root->left,preOrder); 
        dfs(root->right,preOrder); 
    }
};