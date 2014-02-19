class Solution {
public:
   bool isPalindrome(string s) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      transform(s.begin(), s.end(), s.begin(), ::tolower); 
      s.erase(remove_if(s.begin(), s.end(), 
                        [](char c){ return !::isalnum(c); }), s.end());
        
      for(int i=0, j=s.size()-1; i < j; i++, j--)
         if(s[i] != s[j]) return false;
            
      return true;
   }
};
