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
    vector<int> dfs(TreeNode* root, int k, vector<int>& inOrder) {
        if(!root) return {}; 

        dfs(root->left,k,inOrder);

        inOrder.push_back(root->val); 

        dfs(root->right,k,inOrder); 
        return inOrder; 
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inOrder; 
        dfs(root,k, inOrder); 
        return inOrder[k-1]; 
    }
};