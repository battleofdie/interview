class Solution {
public:
   int atoi(const char *str) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      // 1. +/-
      // 2. leading spaces
      // 3. overflow, too big or too small, return INT_MAX or INT_MIN
      // 4. 12a443   will still return 11
      if(str == NULL) return 0;
      
      while( isspace(*str) ) str++;
      
      bool negative = false;
      if(*str == '-' || *str == '+')
      {
         negative = *str == '-';
         str++;
      }
      
      int sum = 0;
      while(*str >= '0' && *str <= '9')
      {
         int n = *str - '0';
         if(!negative && sum > (INT_MAX - n)/10) return INT_MAX;
         if(negative && -sum < (INT_MIN + n)/10) return INT_MIN;
          
         sum = sum*10 + n;
          
         ++str;
      }
      
      return negative ? -sum : sum;
   }
};
