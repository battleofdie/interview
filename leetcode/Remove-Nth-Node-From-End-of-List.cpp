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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *p = head, *q = head, *prev = NULL;
        while(n-- && q) q = q->next;
        
        while(q)
        {
            prev = p;
            p = p->next;
            q = q->next;
        }
        
        if(p) // p is not null, we have to delete it!
        {
            if(prev) prev->next = p->next;
            else head = p->next; // actually, p is head
        }
        
        return head;
    }
};
