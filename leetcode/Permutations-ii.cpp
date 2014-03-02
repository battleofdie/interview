// simplest solution
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
       // Note: The Solution object is instantiated only once and is reused by each test case.
       if(num.empty()) return vector<vector<int> > ();
      
       sort(num.begin(), num.end());
       
       vector<vector<int> > result = {num};
       while(next_permutation(num.begin(), num.end())) // built-in function in <algorithm>
        result.push_back(num);
        
       return result;
    }
};


// alternative, same as permutation i, 
// the only differences are 
// 1. sort num at first
// 2. we only push num[i] when num[i] was not pushed
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > result;
        
        if(num.empty()) return result;
        
        vector<bool> visited(num.size(), false);
        vector<int> path;
        
        sort(num.begin(), num.end());
        permute(num, result, path, visited);
        
        return result;
      }
      
      void permute(vector<int>&num, vector<vector<int> > &result, vector<int> &path, vector<bool> &visited)
      {
          if(path.size() == num.size()) 
          {
              result.push_back(path);
              return;
          }
          
          for(int i=0; i<num.size(); i++)
          {
              if(visited[i] || (i > 0 && visited[i-1] && num[i-1] == num[i])) continue;
              
              visited[i] = true;
              path.push_back(num[i]);
              
              permute(num, result, path, visited);
              
              path.pop_back();
              visited[i] = false;
          }
      }
};
