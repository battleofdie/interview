class Solution {
public:
   int search(int A[], int n, int target) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
        
      if(n<=0) return -1;
      return search(A, n, target, 0, n-1);
   }
    
   int search(int A[], int n, int target, int s, int e)
      {
         if(s > e) return -1;
        
         int mid = s + (e-s)/2;
         if(A[mid] == target) return mid;
        
         if(A[mid] >= A[s]) // using >= in case mid == s
         {
            // s..mid is in order
            if(target >= A[s] && target < A[mid])
               return search(A, n, target, s, mid-1);
            else
               return search(A, n, target, mid+1, e);
         }//
         else // A[mid] < A[s]
         {
            // s..mid is not in order, mid..e is in order
            if(target > A[mid] && target <= A[e]) // 
               return search(A, n, target, mid+1, e); 
            else // if target is not in the range: ( A[mid], A[e] ] 
               return search(A, n, target, s, mid-1);
         }//else
      }
};


// non-recursive version
class Solution {
public:
   int search(int A[], int n, int target) {
      // IMPORTANT: Please reset any member data you declared, as
      // the same Solution instance will be reused for each test case.
      int s = 0, e = n-1, m;
      while(s <= e)
      {
         m = s + (e-s)/2;
         if(target == A[m]) return m;
         else if(target > A[m])
         {
            if(A[m] > A[s])
            {
               s = m+1;
            }
            else
            {
               if(target == A[e]) return e;
               else if(target > A[e])
               {
                  e = m-1;
               }
               else
               {
                  s = m+1;
               }
            }
         }
         else // <
         {
            if(A[m] < A[e])
            {
               e = m-1;
            }
            else
            {
               if(target == A[s]) return s;
               else if(target > A[s])
               {
                  e = m-1;
               }
               else
               {
                  s = m+1;
               }
            }
         }
      }//while
        
      return -1;
   }
};


// or 
class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        // it's my first Amazon phone interview question
        if(n<=0) return -1;
        
        return search(A, n, target, 0, n-1);
    }
    
    int search(int A[], int n, int target, int s, int e)
    {
        if(s > e) return -1;
        
        int mid = s + (e-s)/2;
        if(A[mid] == target) return mid;
        
        if(A[mid] >= A[s]) // using >= in case mid == s
        {
            // s..mid is in order
            if(target >= A[s] && target < A[mid])
                return search(A, n, target, s, mid-1);
            else
                return search(A, n, target, mid+1, e);
        }//
        else // A[mid] < A[s]
        {
            // s..mid is not in order, mid..e is in order
            if(target > A[mid] && target <= A[e]) // 
                return search(A, n, target, mid+1, e); 
            else // if target is not in the range: ( A[mid], A[e] ] 
                return search(A, n, target, s, mid-1);
        }//else
    }
};
