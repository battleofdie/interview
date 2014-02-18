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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL) return NULL;
        
        ListNode *p = head, *q = head;
        
        while(k--) q = (q == NULL? head->next : q->next);
        
        while(q && q->next)
        {
            p = p->next;
            q = q->next;
        }
        
        if(p == NULL || p->next == NULL || q == NULL) return head; // p is the last
        
        ListNode *nh = p->next;
        q->next = head;
        p->next = NULL;
        
        return nh;
    }
};

// alternative

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
    ListNode *rotateRight(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL || k == 0) return head;
        
        int i = k;
        ListNode *it = head;
        while(i-- > 0 && it != NULL)
        {
            it = it->next;
        }
        
        ListNode *last = NULL, *rlast = NULL, *left = head;
        while(it != NULL)
        {
            last = left;
            rlast = it;
            it = it->next;
            left = left->next;
        }
        
        if(last != NULL) last->next = NULL;
        if(rlast != NULL) rlast->next = head;
        
        return left;
    }
};
