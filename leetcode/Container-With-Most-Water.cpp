class Solution {
public:
    int maxArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(height.empty()) return 0;
        
        vector<int> H(1, height[0]);
        for(int i=1; i<height.size(); i++)
            H.push_back((height[i] > H[i-1] ? height[i] : H[i-1]));
        
        int m = INT_MIN;
        for(int i=height.size()-1; i>=0; i--)
        {
            m = height[i] > m ? height[i] : m;
            H[i] = (H[i] < m ? H[i] : m);
        }
        
        int s = 0, e = height.size()-1, max = INT_MIN;
        while(s < e)
        {
            int c = (H[s] < H[e] ? H[s] : H[e]);
            if(max < c*(e-s)) max = c*(e-s);
            
            while(H[s] == c) s++;
            while(H[e] == c) e--;
        }
        
        return max;
    }
}; // Time: O(n); Space: O(n)
