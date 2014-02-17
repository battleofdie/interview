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
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode *temp = head, *last = NULL;
    while(temp && m-- > 1)
      {
	n--;
	last = temp;
	temp = temp->next;
      }
        
    while(n-- > 1)
      {
	ListNode *node = temp->next;
	temp->next = node->next;
            
	// to insert node after last or set it as head
	if(!last)
	  {
	    node->next = head;
	    head = node;
	  }
	else
	  { 
	    ListNode *p = last->next;
	    last->next = node;
	    node->next = p;
	  }
      }//while
        
    return head;
  }
};
