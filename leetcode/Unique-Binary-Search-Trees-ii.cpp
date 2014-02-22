/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
using TreeArray = vector<TreeNode*>;
 
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        TreeArray *result;       
        
        // different way to avoid lot's of copy-constructor xxx
        result = generateTrees(1, n);
        return *result;
    }
    
    TreeArray* generateTrees(int s, int e)
    {
        TreeArray *p = new TreeArray;       
        
        // base case 1
        if(s > e) p->push_back(NULL);
        
        for(int i=s; i<=e; i++)
        {
            TreeArray *left = generateTrees(s, i-1);
            TreeArray *right = generateTrees(i+1, e);
            
            for(auto &l: *left)
            {
                for(auto &r: *right)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    p->push_back(root);
                }
            }//for
        }//for
        
        return p;
    }
};
