class Solution {
public:
    int numDistinct(string S, string T) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // f(m, n) = { f(m-1, n-1) + f(m-1, n) if S[m-1] = T[n-1]; otherwise f(m-1, n);   m>=n
        // f(m, n) = 0 if m < n
        vector<vector<int> > f(S.size()+1, vector<int>(T.size()+1, 0));
        
        // init
        for(int i=0; i<=S.size();i++) f[i][0] = 1;
        
        for(int i=1; i<=S.size(); i++)
        {
            for(int j=1; j<=i && j<=T.size(); j++)
            {
                f[i][j] = (S[i-1] == T[j-1] ? f[i-1][j-1] : 0) + f[i-1][j];
            }
        }
        
        return f[S.size()][T.size()];
    }
};
