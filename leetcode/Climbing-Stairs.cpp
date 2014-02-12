class Solution {
public:
   int climbStairs(int n) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      int f2 = 1, f1 = 1;
      for(int i=1; i<n; i++)
      {
         f2 += f1;
         f1 = f2 - f1;
      }
        
      return f2;
   }
};
