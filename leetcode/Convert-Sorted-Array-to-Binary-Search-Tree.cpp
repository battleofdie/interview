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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(num.empty()) return NULL;
        
        return sortedArrayToBST(num, 0, num.size()-1);
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num, int s, int e){
        if(s > e) return NULL;
        
        int m = s + (e-s)/2;
        TreeNode *root = new TreeNode(num[m]);
        root->left = sortedArrayToBST(num, s, m-1);
        root->right = sortedArrayToBST(num, m+1, e);
        
        return root;
    }
};
