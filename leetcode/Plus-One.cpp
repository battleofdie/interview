class Solution {
public:
   vector<int> plusOne(vector<int> &digits) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      if(digits.empty()) return vector<int>();
        
      vector<int> result(digits.size(), 0);
      int carry = 1;
        
      for(int i=digits.size()-1; i>=0; i--)
      {
         result[i] = (digits[i] + carry) % 10;
         carry = (digits[i] + carry)/10;
      }
        
      if(carry) result.insert(result.begin(), carry);
        
      return result;
   }
};


// older-version
class Solution {
public:
   vector<int> plusOne(vector<int> &digits) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
        
      // yet another method
      // check the tailing 99999 sequence and record the first index of non-9
      int i=digits.size()-1;
      while(i >=0 && digits[i] == 9) i--;
       
      if(i < 0) // overflow case, like: 999999
      {
         vector<int> result(digits.size()+1, 0);
         result[0] = 1;
         return result;
      }
      else
      {
         digits[i]++;
         // then flip the tailing 9-sequence to 0s
         for(int j=i+1; j<digits.size(); j++) 
            digits[j] = 0;
            
         return digits;
      }
   }
};
