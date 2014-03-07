class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > m(n, vector<int>(n, 0));
        
        int v = 1;
        for(int i=0; i<n/2; i++)
        {
            for(int j=i; j<n-i-1; j++) m[i][j] = v++;
            for(int j=i; j<n-i-1; j++) m[j][n-i-1] = v++;
            for(int j=n-i-1; j>i; j--) m[n-i-1][j] = v++;
            for(int j=n-i-1; j>i; j--) m[j][i] = v++;
        }
        
        if(n & 1) m[n/2][n/2] = v;
        return m;
    }
};
