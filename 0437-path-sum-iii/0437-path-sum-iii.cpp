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
    void dfs(TreeNode* root, long long targetSum, int& numPath){
        if(!root){
            return; 
        }

        if(targetSum == root->val){
            numPath++;
            //return; 
        }

        dfs(root->left, targetSum - root->val, numPath); 
        dfs(root->right, targetSum - root->val, numPath); 

    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0; 
        int numPath = 0; 
        dfs(root, targetSum, numPath); 
        numPath += pathSum(root->left, targetSum); 
        numPath += pathSum(root->right, targetSum); 
        return numPath; 
    }
};