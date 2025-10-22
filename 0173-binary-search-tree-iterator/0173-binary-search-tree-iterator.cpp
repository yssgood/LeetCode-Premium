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
class BSTIterator {
    stack<TreeNode*> nodeStack; 
    void pushLeft(TreeNode* root){
        while(root){
            nodeStack.push(root); 
            root = root->left; 
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root); 
    }
    
    int next() {
        TreeNode* curr = nodeStack.top();
        nodeStack.pop();

        pushLeft(curr->right); 
        
        return curr->val; 
    }
    
    bool hasNext() {
        return !nodeStack.empty(); 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */