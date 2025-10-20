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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inorderMap; 
        for(int i = 0; i < inorder.size(); i++){
            inorderMap[inorder[i]] = i; 
        }
        int preIndex = 0; 
        return build(preorder, 0, preorder.size()-1, preIndex, inorderMap); 
    }

    TreeNode* build(vector<int>& preorder, int left, int right, int& preIndex, unordered_map<int,int>& inorderMap){
        //base case 
        if(left > right) return nullptr; 

        int root_val = preorder[preIndex++]; 
        TreeNode* root = new TreeNode(root_val); 

        int mid = inorderMap[root_val]; 
        root->left = build(preorder, left, mid-1, preIndex, inorderMap); 
        root->right = build(preorder, mid + 1, right, preIndex, inorderMap); 

        return root; 
    }
};