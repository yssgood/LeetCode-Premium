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
    int getDiameter(TreeNode* root, int& diameter){
        if(!root) return 0; 
        int left = getDiameter(root->left,diameter); 
        int right = getDiameter(root->right,diameter); 
        diameter = max(diameter, left + right); 
        return max(left,right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0; 
        int diameter = 0; 
        getDiameter(root, diameter); 
        return diameter; 
    }
};

/* 

각 노드에서 얻을 수 있는 정보는 다르고 계산도 다르게 한다 
결국에 비교하는건 subtree 에서 얻을 수 있는 정보이기 때문에 main scope 에서 이동하고 
계산하는 부분은 따로 정해줄 수 있다 

개선된 버전에서는 변수 하나를 이용해서 지속적으로 값을 업데이트 하는 방법도 존재한다. 

*/ 