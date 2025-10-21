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
    int sumNumbers(TreeNode* root) {
        int total = 0;  
        string curr = "";
        helper(root,total,curr);
        return total; 
    }

    void helper(TreeNode* root, int& total, string& curr){
        if(!root) return; 

        curr += to_string(root->val);

        helper(root->left, total, curr); 
        helper(root->right, total, curr); 

        if(!root->left && !root->right){
            //cout << curr << endl; 
            total += stoi(curr); 
        }
        curr.pop_back(); 
    }
};