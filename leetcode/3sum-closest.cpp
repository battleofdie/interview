class Solution {
public:
   int threeSumClosest(vector<int> &num, int target) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      sort(num.begin(), num.end());
        
      int sum = INT_MIN, min = INT_MAX;
      for(int i=0; i<num.size()-2; i++)
      {
         for(int j=i+1, k=num.size()-1; j<k;)
         {
            int temp = num[i]+num[j]+num[k];
            if(temp > target) k--;
            else if(temp < target) j++;
            else return target;
                
            if(abs(temp-target) < min)
            {
               min = abs(temp-target);
               sum = temp;
            }
         }
      }//for
        
      return sum;
   }
};
