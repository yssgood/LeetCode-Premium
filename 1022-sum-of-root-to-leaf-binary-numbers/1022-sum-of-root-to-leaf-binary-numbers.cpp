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
    string path = ""; 
    int sum = 0; 
    int convert(string& path){
        int res = 0; 
        int count = 0; 
        for(int i = path.length()-1; i >= 0; i--){
            if(path[i] == '1') res += pow(2,count); 
            count++; 
        }
        return res; 
    }
    void findPath(TreeNode* root){
        
        if(!root->left && !root->right){
            path += to_string(root->val); 
            sum += convert(path); 
            path.pop_back(); 
            //cout << sum << endl; 
            return; 
        }

        path += to_string(root->val); 

        if(root->left) findPath(root->left); 
        if(root->right) findPath(root->right); 
        path.pop_back(); 
    }
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0; 
        findPath(root); 
        return sum; 
    }
};