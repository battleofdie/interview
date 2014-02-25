/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        return balanced(root) != -1;
    }
    
    int balanced(TreeNode *root){
        if(root == NULL) return 0;
    
        int l = balanced(root->left);
        if(l == -1) return -1;
        
        int r = balanced(root->right);
        if(r == -1) return -1;
        
        if(abs(l-r) > 1) return -1;
        
        return 1 + (l > r ? l : r);
    }
};
