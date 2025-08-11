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
            //cout << root->val << ' ' << targetSum << endl; 
            if(targetSum == root->val){
                //cout << root->val << ' ' << targetSum << endl; 
                //for(int n : container) cout << n << ' '; 
                //cout << endl; 
                container.push_back(root->val); 
                answer.push_back(container); 
                container.pop_back();
                return; 
            } else{
                //container.pop_back();
                return; 
            }
        }

        container.push_back(root->val); 
        //for(int n : container) cout << n << ' ';
        //cout << endl; 
        pathSumHelper(root->left, targetSum - root->val, answer, container);  
        //container.pop_back(); 
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