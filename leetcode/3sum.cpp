class Solution {
public:
   vector<vector<int> > threeSum(vector<int> &num) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      
      vector<vector<int> > result;
      if(num.size() < 2) return result;
        
      sort(num.begin(), num.end());
      for(int i=0; i<num.size()-2;)
      {
         for(int j=i+1, k=num.size()-1; j<k;)
         {
            if(num[i] + num[j] + num[k] > 0) k--;
            else if(num[i] + num[j] + num[k] < 0) j++;
            else
            {
               result.push_back(vector<int>({num[i], num[j], num[k]}));
                    
               j++; k--;
               while(j < k && num[j] == num[j-1]) j++;
               while(k > j && num[k] == num[k+1]) k--;
            }
         }//for
            
         i++;
         while(i < num.size() && num[i] == num[i-1]) i++;
      }//for
        
      return result;
   }
};
