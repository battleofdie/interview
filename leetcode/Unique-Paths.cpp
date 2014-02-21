class Solution {
public:
    int uniquePaths(int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        assert(m > 0 && n > 0);
        
        // f(m, n) = f(m, n-1) + f(m-1, n)
        vector<vector<int> > f(m, vector<int>(n, 1));
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                f[i][j] = f[i][j-1] + f[i-1][j];
        
        return f[m-1][n-1];
    }
};
