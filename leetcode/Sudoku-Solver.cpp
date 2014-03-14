class Solution {
public:
    
      void solveSudoku(vector<vector<char> > &board) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
        solveSudoku(board, 0, 0);
      }
    
   bool solveSudoku(vector<vector<char> > &B, int i, int j){
        if(i > 8) return true;
        if(B[i][j] != '.') return solveSudoku(B, i+(j+1)/9, (j+1)%9);
        
        int r = i/3, c = j/3;
        
        set<char> val;
        for(int k=0; k<9; k++) 
            val.insert({B[i][k], B[k][j], B[r*3 + k/3][c*3 + k%3]});
        
        for(char t='1'; t<='9'; t++)
        {
            if(val.find(t) == val.end())
            {
                B[i][j] = t;
                if(solveSudoku(B, i, j)) return true;
                B[i][j] = '.';
            }
        }
        
        return false;
   }
};
