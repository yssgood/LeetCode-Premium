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
    void pathSumHelper(TreeNode* root, int targetSum, vector<vector<int>>& answer, vector<int>& container){
        if(!root) return; 

        container.push_back(root->val); 

        if(root->left == nullptr && root->right == nullptr){
            if(root->val == targetSum){
                answer.push_back(container); 
            }
            container.pop_back(); 
            return; 
        }

        pathSumHelper(root->left,targetSum-root->val,answer,container); 
        pathSumHelper(root->right,targetSum-root->val,answer,container); 
        container.pop_back(); 

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> answer; 
        vector<int> container; 
        pathSumHelper(root,targetSum,answer,container); 
        return answer; 
    }
};