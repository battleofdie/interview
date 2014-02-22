class Solution {
public:
    int numTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        // recursive function:
        // f(n) = \sum_{i=0}^{n-1} f(i)*f(n-1-i) 
        // f(0) = 1, f(1) = 1
        
        // assume n>= 0
        int f[n+1];
        f[0] = f[1] = 1;
        
        for(int i=2; i<=n; i++)
        {
            int sum = 0;
            for(int j=0; j<i; j++)
            {
                sum += f[j]*f[i-1-j];
            }
            
            f[i] = sum;
        }
        
        return f[n];
    }
};
