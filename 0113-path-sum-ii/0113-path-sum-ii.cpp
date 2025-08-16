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
        if(!root->left && !root->right){
            if(targetSum == root->val){
                container.push_back(root->val); 
                answer.push_back(container); 
                container.pop_back(); //why do we need this? 
            } 
            return; 
        }

        container.push_back(root->val); 
        pathSumHelper(root->left, targetSum - root->val, answer, container);  
        pathSumHelper(root->right, targetSum - root->val, answer, container); 
        container.pop_back(); 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {}; 
        vector<vector<int>> answer; 
        vector<int> container; 
        pathSumHelper(root, targetSum, answer, container);
        return answer; 
    }
};