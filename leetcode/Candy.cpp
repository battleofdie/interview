class Solution {
public:
   int candy(vector<int> &ratings) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
        
      vector<int> candies(ratings.size(), 1);
      for(int i=1; i<ratings.size(); i++)
      {
         if(ratings[i] > ratings[i-1])
            candies[i] = candies[i-1] + 1;
      }
        
      for(int i=ratings.size()-2; i>=0; i--)
      {
         if(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1])
            candies[i] = candies[i+1] + 1;
      }
        
      int sum = 0;
      for_each(candies.begin(), candies.end(), [&sum](int x){sum += x;});
      return sum;
   }
};
