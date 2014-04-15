
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


// more concise
class Solution {
public:
   vector<string> generateParenthesis(int n) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      // make sure left <= right
      return generate(n, n);
   }
   
   vector<string> generate(int l, int r)
   {
       if(l == 0) return vector<string>( {string(r, ')')} ); // only choice
       if(l > r) return vector<string>(); // invalid
       
       vector<string> result;
       vector<string> left = generate(l-1, r);
       for(auto &e: left)
       {
           result.push_back( string("(") + e );
       }
       
       vector<string> right = generate(l, r-1);
       for(auto &e: right)
       {
           result.push_back( string(")") + e);
       }
       
       return result;
   }
};
