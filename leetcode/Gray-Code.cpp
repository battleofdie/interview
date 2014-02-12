class Solution {
public:
   vector<int> grayCode(int n) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      assert(n >= 0);
        
      vector<int> result = {0};
      for(int i=1; i<=n; i++)
      {
         int sz = result.size();
         for(int j = sz-1; j>=0; j--)
            result.push_back(result[j] + (1<<(i-1)));
      }
        
      return result;
   }
};
