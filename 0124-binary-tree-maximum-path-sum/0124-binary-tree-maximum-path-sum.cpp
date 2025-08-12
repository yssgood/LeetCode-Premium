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
    int maxSum; 
    int maxPathSumHelper(TreeNode* root){
        if(!root) return 0; 

        int leftPathSum = max(0, maxPathSumHelper(root->left));
        int rightPathSum = max(0, maxPathSumHelper(root->right));
        int currPath = leftPathSum + rightPathSum + root->val; 

        maxSum = max(maxSum, currPath); 


        return root->val + max(leftPathSum, rightPathSum); 
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN; 
        maxPathSumHelper(root); 
        return maxSum; 
    }
};