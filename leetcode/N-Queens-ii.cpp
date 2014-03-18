class Solution {
public:
    int totalNQueens(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> board(n);

        int count = 0;
        solve(board, count, 0);
        
        return count;
    }
    
    void solve(vector<int> &board, int &count, int row)
    {
        if(row == board.size()) count++;
        
        for(int col=0; col<board.size(); col++)
        {
            if(valid(board, row, col))
            {
                board[row] = col;
                solve(board, count, row+1);
            }
        }
    }
    
    bool valid(vector<int> &board, int row, int col)
    {
        for(int j=0; j<row; j++)
        {
            if( board[j] == col) return false;
            if(abs(row-j) == abs(col-board[j])) return false;
        }//for
        
        return true;
    }
};
