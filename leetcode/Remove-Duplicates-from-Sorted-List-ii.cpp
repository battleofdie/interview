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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode *h = NULL, *l = NULL, *f = head;
        while(f)
        {
            if(f->next && f->val == f->next->val)
            {
                int v = f->val;
                while(f && f->val == v) f = f->next;
            }
            else
            {
                if(l) l->next = f;
                else h = f;
                
                l = f;
                f = f->next;
            }
        }//while
        
        if(l) l->next = NULL;
        
        return h;
    }
};

// Alternatives:

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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *last = NULL, *new_head = NULL, *p = head;
        bool ignore = false; // ignore current p? 
        
        while(p)
        {
            if(p->next && p->val == p->next->val) ignore = true;
            else
            {
                if(!ignore)
                {
                    if(last) last->next = p;
                    else new_head = p;
                    
                    last = p;
                }
                
                ignore = false;
            }//else
            
            p = p->next;
        }
        
        if(last) last->next = NULL;
        return new_head;
    }
};
