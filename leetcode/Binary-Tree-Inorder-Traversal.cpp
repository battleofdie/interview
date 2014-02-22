// with stack
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
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> result;
        
        stack<TreeNode*> S;
        while(root || !S.empty())
        {
            if(root)
            {
                S.push(root);
                root = root->left;
            }
            else
            {
                root = S.top();
                S.pop();
                
                result.push_back(root->val);
                root = root->right;
            }
        }
        
        return result;
    }
};


// alternative, without stack, threaded tree
 Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // let's try naive and simple recursive solution at first
       
        vector<int> result;
        
        // What if stack is not allowed? Use threaded binary tree
        // http://en.wikipedia.org/wiki/Threaded_binary_tree
        // http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
        
        TreeNode *current = root;
        while(current != NULL)
        {
            if(current->left == NULL)
            {
                // left child is NULL, we should visit current node 
                result.push_back(current->val);
                // and set current to it's right child
                current = current->right;
            }
            else
            {
                // if left child is not NULL
                // Make current as right child of the rightmost node in current's left subtree
                TreeNode *pre = current->left;
                while(pre->right !=  NULL && pre->right != current) // we are using the thread here
                    pre = pre->right;
                
                // if pre->right == NULL, no thread, let's build it
                if(pre->right == NULL)
                {
                    pre->right = current;
                    current = current->left;
                }
                else
                {
                    // if we are here, pre->right == current, it was NULL. let's delete this thread
                    pre->right = NULL;
                    result.push_back(current->val);
                    current = current->right;
                }
            }
        }// while
        
        return result;
    }
};
