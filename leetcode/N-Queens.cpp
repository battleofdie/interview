class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> board(n, 0);
        vector<vector<string> > result;
        
        solve(result, board, 0);
        
        return result;
    }
    
    void solve(vector<vector<string> > &result, vector<int> &board, int row){
        if(row == board.size()) 
            result.push_back( convert(board) );
        
        for(int col=0; col<board.size(); col++)
        {
            if(valid(board, row, col))
            {
                board[row] = col;
                solve(result, board, row+1);
            }
        }
    }
    
    bool valid(vector<int> &board, int row, int col){
        for(int i=0; i<row; i++)
        {
            if(board[i] == col) return false;
            if(abs(row-i) == abs(col-board[i])) return false;
        }
        return true;
    }
    
    vector<string> convert(vector<int> &board){
        vector<string> r;
        for(int row=0; row<board.size(); row++)
        {
            string x(board.size(), '.');
            x[board[row]] = 'Q';
            r.push_back(x);
        }
        return r;
    }
};
