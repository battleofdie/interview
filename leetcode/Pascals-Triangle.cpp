class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        
        if(numRows <= 0) return result;
        
        result.push_back(vector<int>(1, 1));
        while(numRows-- > 1)
        {
            const vector<int> &x = result.back();
            vector<int> level(1, 1);
            for(int i=1; i<x.size(); i++)
            {
                level.push_back(x[i-1] + x[i]);
            }
            
            level.push_back(1);
            result.push_back(level);
        }
        
        return result;
    }
};
