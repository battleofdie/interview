class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        // optimized way is:
        // allocate space result[rowIndex+1]
        // for example k = 3, result = [0, 0, 0, 0]
        // next step result = [1, 0, 0, 0]
        // next      result = [1, 1, 0, 0]
        // next      result = [1, 2, 1, 0]
        // next      result = [1, 3, 3, 1]
        
        if(rowIndex < 0) return vector<int>();
        
        vector<int> result(rowIndex+1, 0);
        result[0]= 1;
        
        for(int i=1; i<=rowIndex; i++)
            for(int j=i; j>=1; j--)
                result[j] += result[j-1];
        
        return result;
    }
};
