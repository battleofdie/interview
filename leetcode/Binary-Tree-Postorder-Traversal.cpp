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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        stack<TreeNode*> S;
        S.push(root);
        while(!S.empty())
        {
            TreeNode *top = S.top();
            S.pop();
            
            if(!top) continue;
            result.push_back(top->val);
            S.push(top->left);
            S.push(top->right);
        }
        
        return vector<int>(result.rbegin(), result.rend());
    }
};
