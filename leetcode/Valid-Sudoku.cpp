class Solution {
public:
   bool isValidSudoku(vector<vector<char> > &board) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      assert(board.size() == 9);
        
      vector<int> row(9, 0), col(9, 0), rec(9, 0);
      for(int i=0; i<9; i++)
      {
         for(int j=0; j<9; j++)
         {
            if(board[i][j] != '.')
            {
               int x = 1 << (board[i][j] - '0');
               if(row[i] & x) return false;
               else row[i] |= x;
                    
               if(col[j] & x) return false;
               else col[j] |= x;
                    
               int k = (i/3)*3 + j/3;
               if(rec[k] & x) return false;
               else rec[k] |= x;
            }
         }
      }
      return true;
   }
};
