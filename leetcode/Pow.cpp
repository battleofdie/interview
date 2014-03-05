class Solution {
public:
    double pow(double x, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(x == 0) return 0;
        if(n == 0) return 1;
        
        if(n == 1) return x;
        if(n == -1) return 1/x;
        
        double part = pow(x, n/2);
        if(n % 2 == 0) return part*part;
        
        if(n > 0) return part*part*x;
        else return part*part/x;
    }
};
