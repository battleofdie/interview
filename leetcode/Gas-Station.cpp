class Solution {
public:
   int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
      assert(gas.size() == cost.size());
       
      int sum = 0, total = 0, index = -1;
      for(int i=0; i<gas.size(); i++)
      {
         total += gas[i] - cost[i];
         sum += gas[i] - cost[i];
         if(sum < 0)
         {
            sum = 0;
            index = i;
         }
      }
       
      return total < 0 ? -1 : index+1;
   }
};
