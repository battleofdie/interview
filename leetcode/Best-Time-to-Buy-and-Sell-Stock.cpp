class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int max = 0, min = INT_MAX;
        for(auto x: prices)
        {
            if(x < min) min = x;
            else if(max < x - min) 
                max = x - min;
        }
        return max;
    }
};
