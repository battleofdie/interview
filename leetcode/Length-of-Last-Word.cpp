class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(s == NULL) return 0;
        
        int p = 0, r = 0;
        while(*s)
        {
            if(*s == ' ')
            { 
                p = r; 
                r = 0; 
                while(*s == ' ') s++;
            }
            else
            {
                r++;
                s++;
            }
        }
      
        return (r == 0 ? p : r);
    }
};
