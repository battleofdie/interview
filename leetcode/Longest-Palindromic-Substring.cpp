class Solution {
public:
    string longestPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int start = 0, length = 0;
        for(int i=0; i<s.size(); i++)
        {
            checkPalindrome(s, i-1, i+1, start, length); // at s[i]
            
            if(i+1 < s.size() && s[i] == s[i+1]) // at s[i] & s[i+1]
                checkPalindrome(s, i-1, i+2, start, length); 
        }
        
        return s.substr(start, length);
    }
    
    void checkPalindrome(string s, int j, int k, int &start, int &length){
        for(; j >= 0 && k < s.size() && s[j] == s[k]; --j, ++k) ;
        if(k-j-1 > length)
        {
            length = k-j-1;
            start = j+1;
        }
    }
};
