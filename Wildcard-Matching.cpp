class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(s == NULL || p == NULL) return false;
        
        // recursive solution is not going to work, try DP
        // f(m, n) = f(m-1, n-1) if s[m] == p[n] or p[n] == '?'
        //         = f(m-1, n) or f(m-2, n) or .. or f(0, n) or f(m, n-1) if p[n] == '*'
        //         = false otherwise
        // Oh, shit Memory Limit Exceeded! As expected.
        // Now let's try to optimize it!
        // Use the following function:
        // f(m, n) = f(m-1, n-1) if s[m] == p[n] or p[n] == '?'
        //         = g(n) || f(m, n-1) if p[n] == '*'
        //         = false; otherwise
        // 
        // Now all we need is to track f(m-1, n-1) and f(m, n-1), easy enough! 
        // F[S.size()+1] to track every f(m, n), one column at a time
        // bool last to track f(m-1, n-1)
        // actually the previous F[j] is f(j, i-1)

        string S = s, P = p, temp = p;
        
        temp.erase(remove_if(temp.begin(), temp.end(), 
                             [](char c){ return c == '*'; }), temp.end());
                    
        if(temp.size() > S.size()) return false;

        // previous column
        vector<bool> F(S.size()+1, false);
        F[0] = true;
        
        // for each column
        for(int i=1; i<=P.size(); i++)
        {
            bool gn = false, last = F[0];
            for(int j=0; j<=S.size(); j++)
            {
                if(j>0 && (S[j-1] == P[i-1] || P[i-1] == '?'))
                {
                    if(last != F[j])
                    {
                        last = !last;
                        F[j] = !F[j];
                    }
                    gn = gn || F[j];
                }
                else if(P[i-1] == '*')
                {
                    last = F[j];
                    F[j] = gn || F[j];  /* f(j, i) = gi || f(j, i-1) */
                    gn = F[j];
                }
                else
                {
                    last = F[j];
                    F[j] = false;
                }
            }
        }

        return F[S.size()];
    }
};
