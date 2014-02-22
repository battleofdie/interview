class Solution {
public:
    bool isPalindrome(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // was based on wrong assumption, -1 is not palindromes
        isPalindrome(x, x);
    }

    bool isPalindrome(int x, int &y){
        if(x < 0) return false;
        if(x == 0) return true;
    
        if(!isPalindrome(x/10, y) || x%10 != y%10) return false;
    
        y /= 10;
        return true;
    }
};
