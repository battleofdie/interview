class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(*s == '\0')
        {
            while(*p != '\0' && *(p+1) == '*') p += 2;
            return (*p == '\0' ? true : false);
        }

        if(*s == *p || *p == '.')
            return (*(p+1) == '*') ? isMatch(s, p+2) || isMatch(s+1, p) : isMatch(s+1, p+1);
        else
            return (*p != '\0' && *(p+1) == '*') ? isMatch(s, p+2) : false;
    }
};
