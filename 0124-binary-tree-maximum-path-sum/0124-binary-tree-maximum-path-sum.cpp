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
    int maxPath; 
    int maxPathSumHelper(TreeNode* root, int currSum){
        if(!root) return 0; 

        int left = max(0,maxPathSumHelper(root->left, currSum + root->val)); 
        int right = max(0,maxPathSumHelper(root->right, currSum + root->val)); 
        int currPath = root->val + left + right; 

        maxPath = max(maxPath, currPath); 

        return root->val + max(left,right); 
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0; 
        maxPath = INT_MIN; 
        maxPathSumHelper(root,0); 
        return maxPath;  
    }
};