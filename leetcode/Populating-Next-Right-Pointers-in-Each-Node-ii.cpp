/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while(root)
        {
            TreeLinkNode *node = root;
            while(node)
            {
                if(node->left && node->right)
                {
                    node->left->next = node->right;
                    node->right->next = getNext(node->next);
                }
                else if(node->left)
                    node->left->next = getNext(node->next);
                else if(node->right)
                    node->right->next = getNext(node->next);
                
                node = node->next;
            }
            
            root = getNext(root);
        }//while
    }
    
    TreeLinkNode *getNext(TreeLinkNode* node)
    {
        // get the first child in link start with node
        while(node)
        {
            if(node->left) return node->left;
            if(node->right) return node->right;
            node = node->next;
        }
        return NULL;
    }
};
