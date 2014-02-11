class Solution {
public:
   int trap(int A[], int n) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      if(n == 0) return 0;
        
      int temp[n];
        
      temp[0] = A[0];
      for(int i=1; i<n; i++)
      {
         temp[i] = temp[i-1] > A[i] ? temp[i-1] : A[i];
      }
        
      int sum = 0, max = A[n-1];
      for(int i=n-2; i>0; i--)
      {
         if(A[i] > max) max = A[i];
         sum += ((temp[i] < max) ? temp[i] : max) - A[i];
      }
        
      return sum;
   }
};
