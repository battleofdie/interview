class Solution {
public:
    int minDistance(string word1, string word2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int f[word1.size()+1][word2.size()+1];
        for(int i=0; i<=word1.size(); i++) f[i][0] = i;
        for(int i=0; i<=word2.size(); i++) f[0][i] = i;
            
        for(int m=1; m<=word1.size(); m++)
        {
            for(int n=1; n<=word2.size(); n++)
            {
                if(word1[m-1] == word2[n-1])
                {
                    f[m][n] = f[m-1][n-1];
                }
                else
                {
                    f[m][n] = (f[m-1][n] < f[m][n-1] ? f[m-1][n] : f[m][n-1]);
                    f[m][n] = (f[m-1][n-1] < f[m][n] ? f[m-1][n-1] : f[m][n]) + 1;
                }
            }
        }//for
        
        return f[word1.size()][word2.size()];
    }
};
