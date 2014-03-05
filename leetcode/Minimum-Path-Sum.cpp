class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // Simple DP: f(m, n) = min{ f(m-1, n), f(m, n-1) } + v(m, n)
        if(grid.empty() || grid[0].empty()) return 0;
        
        vector<vector<int> > f(grid.size(), vector<int>(grid[0].size(), 0));
        
        f[0][0] = grid[0][0];
        for(int i=1; i<grid.size(); i++)
            f[i][0] = grid[i][0]+f[i-1][0];
            
        for(int j=1; j<grid[0].size(); j++) 
            f[0][j] = grid[0][j] + f[0][j-1];
        
        for(int i=1; i<grid.size(); i++)
        {
            for(int j=1; j<grid[i].size(); j++)
                f[i][j] = (f[i-1][j] < f[i][j-1] ? f[i-1][j] : f[i][j-1]) + grid[i][j];
        }
        return f[grid.size()-1][grid[0].size()-1];
    }
};
