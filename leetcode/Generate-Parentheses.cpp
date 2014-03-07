class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return generateParenthesis(n, n);
    }
    
    vector<string> generateParenthesis(int l, int r)
    {
        if(l > r) return vector<string>(); // error
        
        if(l == 0) 
        {
            string str(r, ')');
            return vector<string>({str});
        }
        
        vector<string> result;
        vector<string> part1 = generateParenthesis(l-1, r);
        for(auto &e: part1)
        {
            result.push_back("(" + e);
        }
            
        if(l < r) 
        {
            vector<string> part2 = generateParenthesis(l, r-1);
            for(auto &e: part2)
                result.push_back(")" + e);
        }
        
        return result;
    }
};
