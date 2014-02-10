class Solution {
public:
   vector<vector<int> > fourSum(vector<int> &num, int target) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
        
      vector<vector<int> > result;
        
      sort(num.begin(), num.end());
        
      for(int i=0; i+3<num.size();)
      {
         for(int j=i+1; j+2<num.size();)
         {
            for(int m=j+1, n=num.size()-1; m<n;)
            {
               int sum = num[i] + num[j] + num[m] + num[n];
               if(sum > target) n--;
               else if(sum < target) m++;
               else
               {
                  result.push_back({num[i], num[j], num[m], num[n]});
                        
                  m++; n--;
                  while(m < n && num[m] == num[m-1]) m++;
                  while(n > m && num[n] == num[n+1]) n--;
               }
            } // for m, n
                
            j++;
            while(j<num.size()-2 && num[j] == num[j-1]) j++;
         } // for j
            
         i++;
         while(i<num.size()-3 && num[i] == num[i-1]) i++;
      }//for i
        
      return result;
   }
};
