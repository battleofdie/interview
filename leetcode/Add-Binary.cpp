class Solution {
public:
    string addBinary(string a, string b) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string sum;
        
        auto ra = a.rbegin(), rb = b.rbegin();
        int carry = 0;
        while(carry || ra != a.rend() || rb != b.rend())
        {
            int s = 0;
            if(ra != a.rend()){ s += (*ra - '0'); ++ra; }
            if(rb != b.rend()){ s += (*rb - '0'); ++rb; }
    
            sum.push_back('0' + (s+carry) % 2);
            carry = (s+carry) / 2;
        }
        
        reverse(sum.begin(), sum.end());
        
        return sum;
    }
};
