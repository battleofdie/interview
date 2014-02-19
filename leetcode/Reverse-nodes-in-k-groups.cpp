#include <iostream>

using namespace std;

struct ListNode{
   int val;
   ListNode *next;
   ListNode(int v):val(v),next(NULL){}
};

class Solution {
public:
   ListNode *reverseKGroup(ListNode *head, int k) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      ListNode *p = head, *last = NULL;
      while(p)
      {
          int c = 0;
          ListNode *q = p;
          while(c++ < k && q) q = q->next;
          
          if(--c == k)
          {
              // at least k nodes before node p, we should reverse nodes in range [p, q) 
              ListNode *h = p, *new_head = NULL;
              while(h != q)
              {
                  // insert h into new list
                  ListNode *temp = h->next;
                  h->next = new_head;
                  new_head = h;
                  h = temp;
              }
              
              if(last) last->next = new_head;
              else head = new_head;
              
              last = p;
              last->next = q;
          }
          
          p = q; // move to next group
      }//while
      
      return head;
   }
};

int main(int argc, char *argv[])
{
   ListNode *head = new ListNode(1);
   head->next = new ListNode(2);

   Solution slt;
   head = slt.reverseKGroup(head, 2);

   while(head)
   {
      cout << head->val << endl;
      head = head->next;
   }
   
   return 0;
}
