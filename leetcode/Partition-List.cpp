/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *lh = NULL, *ll = NULL, *rh = NULL, *rl = NULL, *cursor = head;
        while(cursor)
        {
            if(cursor->val >= x) append(rh, rl, cursor);
            else append(lh, ll, cursor);
        }
        
        if(ll) ll->next = rh;
        if(rl) rl->next = NULL;
        
        return lh != NULL ? lh : rh;
    }
    
    void append(ListNode* &h, ListNode* &l, ListNode* &node)
    {
        if(l) l->next = node;
        else h = node;
        
        l = node;
        node = node->next;
    }
};
