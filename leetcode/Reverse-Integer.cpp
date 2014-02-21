class Solution {
public:
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int result = 0;
        while(x != 0)
        {
            if(result > 0 && result > (INT_MAX - x % 10)/10) return INT_MAX;
            if(result < 0 && result < (INT_MIN - x % 10)/10) return INT_MIN;
         
            result = result*10 + x % 10;
            x /= 10;
        }
     
        return result;
    }
};
