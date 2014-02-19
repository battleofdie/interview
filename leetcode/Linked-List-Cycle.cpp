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
   bool hasCycle(ListNode *head) {
      // IMPORTANT: Please reset any member data you declared, as
      // the same Solution instance will be reused for each test case.
      ListNode *slow = head, *fast = head;
      while(fast)
      {
         slow = slow->next;
         fast = fast->next;
         if(fast) 
         {
            fast = fast->next;
            if(slow == fast) return true;
         }
      }//while
        
      return false;
   }
};
