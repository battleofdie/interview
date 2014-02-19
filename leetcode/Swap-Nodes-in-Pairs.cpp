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
    ListNode *swapPairs(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *p = head, *last = NULL;
        while(p && p->next)
        {
            // swap p and p->next
            ListNode *temp = p->next;
            p->next = temp->next;
            temp->next = p;
            
            if(last) last->next = temp;
            else head = temp;
            
            last = p;
            p = p->next;
        }
        
        return head;
    }
};
