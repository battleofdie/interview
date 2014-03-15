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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *head = NULL, *last = NULL;
        while(l1 && l2)
        {
            ListNode *min = l1;
            if(min->val < l2->val)
                l1 = l1->next;
            else
            {
                min = l2;
                l2 = l2->next;
            } 
            
            if(head == NULL) head = min;
            else last->next = min;
            
            last = min;
        }
        
        ListNode *r = l1 ? l1 : l2;
        if(head == NULL) head = r;
        else last->next = r;
        
        return head;
    }
};
