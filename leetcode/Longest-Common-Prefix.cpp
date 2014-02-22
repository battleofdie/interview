class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // This is the fucking brute force solution! 
        if(strs.empty()) return string();
        
        string sub;
        for(int i=0; i<strs[0].size(); i++)
        {
            for(auto str: strs)
            {
                if(strs[0][i] != str[i])
                    return sub;
            }
            sub.push_back(strs[0][i]);
        }
        return sub;
    }
};
