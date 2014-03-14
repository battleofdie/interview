class Solution {
public:
    bool isValid(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<char> S;
        for(auto c: s)
        {
            if(c == '{' || c == '[' || c == '(') S.push(c);
            else
            {
                if(S.empty()) return false;
                
                char top = S.top();
                if(top == '{' && c == '}' || top == '[' && c == ']' || top == '(' && c == ')')
                    S.pop();
                else 
                    return false;
            }
        }
        return S.empty();
    }
};
