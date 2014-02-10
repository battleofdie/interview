class Solution {
public:
   int longestConsecutive(vector<int> &num) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      int max = 0;
        
      unordered_map<int, int> M;
      for(auto e: num)
      {
         int len = 0;
         if(M[e] != 0) continue;

         int lower = e - M[e-1];
         int upper = e + M[e+1];
            
         len = upper - lower + 1;
         M[e] = M[lower] = M[upper] = len;
         max = len > max ? len : max;
      }//for
        
      return max;
   }
};


