// naive way! two-pass

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
   RandomListNode *copyRandomList(RandomListNode *head) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
        
      if(head == NULL) return head;
        
      unordered_map<RandomListNode*, RandomListNode*> M;
        
      RandomListNode *new_head = NULL, *last = NULL;
      RandomListNode *p = head;
        
      while(p)
      {
         if(new_head == NULL)
         {
            new_head = last = new RandomListNode(p->label);
         }
         else
         {
            last->next = new RandomListNode(p->label);
            last = last->next;
         }
            
         M[p] = last;
         p = p->next;
      }//while
        
      p = head;
      RandomListNode *q = new_head;
      while(p)
      {
         q->random = M[p->random];
         p = p->next;
         q = q->next;
      }
        
      return new_head;
   }
};


// alternative, one-pass
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        unordered_map<RandomListNode*, RandomListNode*> M;
        M[NULL] = NULL;
        
        RandomListNode *new_head = NULL, *last = NULL, *p = head;
        while(p)
        {
            if(M.find(p) == M.end()) M[p] = new RandomListNode(p->label);
                
            if(M.find(p->random) == M.end())
            {
                M[p]->random = new RandomListNode(p->random->label);
                M[p->random] = M[p]->random;
            }

            M[p]->random = M[p->random];
            
            if(last) last->next = M[p];
            else new_head = M[p];
            
            last = M[p];
            p = p->next;
        } //while
        
        return new_head;
    }
};
