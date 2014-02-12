class Solution {
public:
   string getPermutation(int n, int k)
      {
         vector<int> fac(n+1, 1); 
         for(int i=1; i<n+1; i++) fac[i] = i*fac[i-1];
       
         vector<char> digits = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
       
         string result;
         for(int i=n; i>=1; i--)
         {
            int x = (k-1)/fac[i-1] + 1;
           
            result += digits[x-1];
            digits.erase(digits.begin() + x-1);
           
            k -= (x-1)*fac[i-1];
         }//for
       
         return result;
      }
};
