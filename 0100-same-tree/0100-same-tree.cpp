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
    //idea : we move p and q if they meet conditions 
    //if p AND q are both nullptr, then we have reached to the destination 
    //if p == nullptr while q is not, then this is false condition (same thing applies to other)
    //if their values are different, then it is false condition = 
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true; 
        }

        if(p == nullptr && q != nullptr || p != nullptr && q == nullptr){
            return false; 
        }

        //if(p == nullptr || q == nullptr) if q is nullptr, think what happens 

        if(p->val != q->val){
            return false; 
        }

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right); 
    }
};