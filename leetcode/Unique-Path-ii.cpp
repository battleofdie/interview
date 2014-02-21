class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
         if(obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
         
         int m = obstacleGrid.size(), n = obstacleGrid[0].size();
         vector<vector<int> > f(m, vector<int>(n, 0));
         
         for(int i=0; i<m && obstacleGrid[i][0] == 0; i++) 
            f[i][0] = 1;
         for(int i=0; i<n && obstacleGrid[0][i] == 0; i++)
            f[0][i] = 1;
            
         for(int i=1; i<m; i++)
         {
             for(int j=1; j<n; j++)
                 if(obstacleGrid[i][j] == 0) f[i][j] = f[i-1][j] + f[i][j-1];
          }
          
          return f[m-1][n-1];
    }
};
