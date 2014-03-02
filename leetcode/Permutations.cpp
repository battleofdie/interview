class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return permute(num, 0);
      }
      
      vector<vector<int> > permute(vector<int> &num, int idx)
      {
          if(idx >= num.size()) return vector<vector<int> >();
          if(idx == num.size()-1) return vector<vector<int> >({vector<int>({num.back()})});
          
          vector<vector<int> > part = permute(num, idx+1);
          vector<vector<int> > result;
          for(auto &e: part)
          {
              for(int i=0; i<=e.size(); i++)
              {
                  vector<int> t = e;
                  t.insert(t.begin()+i, num[idx]);
                  result.push_back(t);
              }
          }
          
          return result;
      }
};


// alternative
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > result;
        
        if(num.empty()) return result;
        
        vector<bool> visited(num.size(), false);
        vector<int> path;
        
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
              if(visited[i]) continue;
              
              visited[i] = true;
              path.push_back(num[i]);
              
              permute(num, result, path, visited);
              
              path.pop_back();
              visited[i] = false;
          }
      }
};
