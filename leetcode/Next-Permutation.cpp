class Solution {
public:
   void nextPermutation(vector<int> &num) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
        
      if(num.empty()) return;
        
      int i = num.size()-1;
      while(i >= 1 && num[i-1] >= num[i]) --i;
        
      if(i > 0) 
      {
         int x = i;
         while(x < num.size() && num[x] > num[i-1]) x++;
         --x;
                
         int temp = num[i-1];
         num[i-1] = num[x];
         num[x] = temp;
      }
        
      // if i == 0, we also reverse num!
      reverse(num.begin()+i, num.end());
   }
}; 
