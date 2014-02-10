class Solution {
public:
   vector<int> twoSum(vector<int> &numbers, int target) {
        
      unordered_map<int, int> M;
      for(int i=0; i<numbers.size(); i++)
      {
         if(M.find(target - numbers[i]) == M.end())
         {
            M[numbers[i]] = i+1;
         }
         else
         {
            return vector<int>({M[target-numbers[i]], i+1});
         }
      }
      
      return vector<int>({});
   }
};
