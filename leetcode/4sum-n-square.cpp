/**
 * @file   4sum-n-square.cpp
 * @author Jesse Chen <jaleel.chen@gmail.com>
 * @date   Tue Feb 11 10:15:55 2014
 * 
 * @brief  Naive n^2 solution for 4-Sum. it's slower than n^3. it must be an implementary issue.
 * 
 * 
 */
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
   vector<vector<int> > fourSum(vector<int> &num, int target) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
        
      vector<vector<int> > result;

      if(num.empty()) return result;

      sort(num.begin(), num.end());
        
      unordered_multimap<int, int> MM;
      unordered_map<int, bool> visited;

      int sz = num.size();
      for(int i=0; i<sz; i++)
      {
         if(i > 0 && num[i-1] == num[i]) continue;
         for(int j=i+1; j<sz; j++)
         {
            if(j-1 > i && num[j-1] == num[j]) continue; 
            MM.insert({{num[i] + num[j], i*sz + j}});
         }
      }
        
      for(int i=0; i<sz; i++)
      {
         for(int j=i+1; j<sz; j++)
         {
            int t = target - (num[i] + num[j]);
            if(MM.find(t) != MM.end())
            {
               auto range = MM.equal_range(t);
               for(auto it = range.first; it != range.second; ++it)
               {
                  int m = it->second / sz;
                  int n = it->second % sz; // note that m < n and i < j
                     
                  vector<int> index = {i, j, m, n};
                  sort(index.begin(), index.end());
                  auto pos = unique(index.begin(), index.end());
                  index.resize(distance(index.begin(), pos));
                  if(index.size() == 4)
                  {
                     int n1 = num[ index[0] ] - num[0];
                     int n2 = num[ index[1] ] * sz;
                     int n3 = num[ index[2] ] * sz*sz;
                     int n4 = num[ index[3] ] * sz*sz*sz;

                     if(!visited[n1+n2+n3+n4])
                     {
                        visited[n1+n2+n3+n4] = true;
                        vector<int> sol;                          
                        for_each(index.begin(), index.end(), [&sol, &num](int x){ sol.push_back(num[x]); });
                        result.push_back(sol);
                     }
                  }
               }//for
            }
         }
      }//for

      return result;
   }
};


int main(int argc, char *argv[])
{
   Solution slt;

   vector<int> num = {-3,-2,-1,0,0,1,2,3}; // {1, 0, -1, 0, -2, 2};

   auto result = slt.fourSum(num, 0);

   for(auto &e: result)
   {
      for(auto x: e)
      {
         cout << x << " ";
      }
      cout << endl;
   }
   return 0;
}
