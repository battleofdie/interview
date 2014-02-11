class Solution {
public:
   int removeElement(int A[], int n, int elem) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
       
      int i =0, last = n-1;
      while(i <= last)
      {
         if(A[i] == elem) A[i] = A[last--];
         else i++;
      }
       
      return last+1;
   }
};
