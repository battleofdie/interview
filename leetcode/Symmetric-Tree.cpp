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
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!root) return true;
        
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode *left, TreeNode *right)
        {
            if(left == NULL && right == NULL) return true;
            if(left == NULL && right != NULL || left != NULL && right == NULL) 
                return false;
        
            return left->val == right->val 
                && isSymmetric(left->right, right->left) 
                && isSymmetric(left->left, right->right);
        }
};
