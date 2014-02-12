class Solution {
public:
   void setZeroes(vector<vector<int> > &matrix) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      bool row = false, col = false;
      for(int i=0; i<matrix.size(); i++)
         for(int j=0; j<matrix[i].size(); j++)
         {
            if(matrix[i][j] == 0)
            {
               matrix[i][0] = 0;
               matrix[0][j] = 0;
               if(i == 0) row = true;
               if(j == 0) col = true;
            }
         }
        
      for(int i=1; i<matrix.size(); i++)
         for(int j=1; j<matrix[i].size(); j++)
         {
            if(matrix[0][j] == 0 || matrix[i][0] == 0)
               matrix[i][j] = 0;
         }
        
      // first row should be 0
      if(row) matrix[0] = vector<int>(matrix[0].size(), 0);
      if(col) for(int i=0; i<matrix.size(); i++) matrix[i][0] = 0;
   }
};
