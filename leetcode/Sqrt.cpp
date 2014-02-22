class Solution {
public:
    int sqrt(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        // Newton's method
        // Choose X0 close to x
        // Xn1 = (Xn1 + x/Xn1)/2;
        // sqrt(x) = lim{Xn} for n -> INF
        
        if(x == 0) return 0;
        if(x < 0) return -1;
        
        double xn = -1, xn1 = x;
        while(fabs(xn - xn1) >= 1)
        {
            xn = xn1;
            xn1 = (xn1 + x/xn1)/2;
        }
        
        return xn1;
    }
};

// alternative, not fast enough for input: 2147483647
// Binary search
class Solution {
public:
    int sqrt(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // binary search
        int s = 0, e = x;
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            if(x > mid*mid) s = mid+1;
            else if(x < mid*mid) e = mid-1;
            else return mid;
        }
        
        return e;
    }
};
