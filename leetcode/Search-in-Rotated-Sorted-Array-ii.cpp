class Solution {
public:
   bool search(int A[], int n, int target) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      if(n <= 0) return false;
      else return search(A, n, target, 0, n-1);
   }
    
   bool search(int A[], int n, int target, int s, int e)
      {
         if(s > e) return false;
        
         int mid = s + (e-s)/2;
       
         // base case:
         if(A[mid] == target) 
            return true;
               
         if(A[mid] > A[s])
         {
            // s..mid is in order
            if(target >= A[s] && target < A[mid]) // target is in the range s..mid 
               return search(A, n, target, s, mid-1);
            else 
               return search(A, n, target, mid+1, e);
         }
         else if(A[mid] < A[s])
         {
            // mid..e is in order
            if(target > A[mid] && target <= A[e]) // it's in right side, e..mid
               return search(A, n, target, mid+1, e);
            else
               return search(A, n, target, s, mid-1);
         }
         else // A[mid] == A[s]
         {
            // s..mid or mid..e are all repeats! what a bummer!
            // A[] = {2, 2, 2, 2, 3, 4, 2} or A[] = {1, 3, 1, 1, 1}
            if(A[mid] != A[e])
               return search(A, n, target, mid+1, e);
            else
               return search(A, n, target, s, mid-1) || search(A, n, target, mid+1, e);
         }
        
         // time complexity:
         // if elements are unique, then O(lgn)
         // otherwise it might be O(n)
      }
};


// or 
class Solution {
public:
    bool search(int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        return search(A, 0, n-1, target) != -1;
    }
    
    int search(int A[], int s, int e, int target)
    {
        if(s > e) return -1;
        if(s == e) return (A[s] == target ? s : -1);
        
        int m = s + (e-s)/2;
        
        if(target > A[m])
        {
            if(A[m] < A[e])
            {
                if(target > A[e]) return search(A, s, m-1, target);
                else if(target < A[e]) return search(A, m+1, e, target);
                else return e;
            }
            else if(A[m] > A[e])
            {
                return search(A, m+1, e, target);
            }
            else
            {
                int result = search(A, s, m-1, target);
                return result != -1 ? result : search(A, m+1, e, target);
            }
        }
        else if(target < A[m])
        {
            if(A[m] < A[e])
            {
                return search(A, s, m-1, target);
            }
            else if(A[m] > A[e])
            {
                if(target > A[e]) return search(A, s, m-1, target);
                else if(target < A[e]) return search(A, m+1, e, target);
                else return e;
            }
            else
            {
                int result = search(A, s, m-1, target);
                return result != -1 ? result : search(A, m+1, e, target);
            }
        }
        else
        {
            return m;
        }
    }
};
