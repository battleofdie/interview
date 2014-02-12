class Solution {
public:
   int singleNumber(int A[], int n) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
        
      int b = 32, result = 0;
      while(b--)
      {
         int x = 0;
         for(int i=0; i<n; i++)
         {
            x += (A[i] & (1<<b)) >> b;
         }
         result |= (x%3)<<b;
      }
        
      return result;
   }
};
