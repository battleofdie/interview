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
   ListNode *detectCycle(ListNode *head) {
      // IMPORTANT: Please reset any member data you declared, as
      // the same Solution instance will be reused for each test case.
      ListNode *s = head, *f = head;
      while(f)
      {
         s = s->next;
         f = f->next;
         if(f)
         {
            f = f->next;
            if(s == f) break;
         }
      }
        
      if(f == NULL) return NULL;
        
      s = head;
      while(s != f)
      {
         s = s->next;
         f = f->next;
      }
        
      return s;
   }
};
