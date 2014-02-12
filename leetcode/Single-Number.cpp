class Solution {
public:
   int singleNumber(int A[], int n) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      int result = 0;
       
      while(n--) result ^= A[n];
       
      return result;
   }
};
