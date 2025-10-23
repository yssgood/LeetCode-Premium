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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> answer; 
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()){
            int size = q.size(); 
            long long total = 0; 
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front(); 
                q.pop(); 
                total += curr->val; 
                if(i == size-1){
                    answer.push_back((double)((double)total / (double)size)); 
                }

                if(curr->left) q.push(curr->left); 
                if(curr->right) q.push(curr->right); 

            }
        }
        return answer; 
    }
};