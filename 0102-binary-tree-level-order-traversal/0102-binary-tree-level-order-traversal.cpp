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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> answer; 
        vector<int> container; 
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front(); 
                q.pop(); 
                container.push_back(curr->val); 
                if(curr->left != nullptr) q.push(curr->left); 
                if(curr->right != nullptr) q.push(curr->right); 
            }
            answer.push_back(container); 
            container.clear(); 
        }

        return answer; 
    }
};