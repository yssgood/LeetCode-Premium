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
    int getMinimumDifference(TreeNode* root) {
        int answer = INT_MAX; 
        int prev = INT_MAX; 
        helper(root,answer,prev);
        return answer; 
    }
    void helper(TreeNode* root, int& answer, int& prev){
        if(!root) return; 

        helper(root->left, answer, prev);
        if(prev != INT_MAX) answer = min(answer, abs(prev - root->val)); 
        prev = root->val; 
        helper(root->right, answer, prev); 
    }
};