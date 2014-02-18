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
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!head) return NULL;
        
        ListNode *last = head, *p = last->next;
        while(p)
        {
            if(last->val != p->val)
            {
                last->next = p;
                last = p;
            }
            
            p = p->next;
        }
        
        last->next = NULL;
        
        return head;
    }
};
