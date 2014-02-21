class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case
        vector<string> result;
        unordered_map<string, int> M;
        for(int i=0; i<strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(M.find(temp) == M.end()) 
                M[temp] = i;
            else
            {
                if(M[temp] != -1)
                    result.push_back(strs[M[temp]]);
                    
                result.push_back(strs[i]);
                M[temp] = -1;
            }
        }
        
        return result;
    }
};
