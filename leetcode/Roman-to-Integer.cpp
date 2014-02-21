class Solution {
public:

    int romanToInt(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        static unordered_map<string, int> um({{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, 
                                                                                                                         {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}});
                                             
        if(s.empty()) return 0;
        if(s.size() == 1) return um[s]; // if s is not in um, then it will return 0, i.e., the default value
        
        if(um.find(s.substr(0, 2)) != um.end())
            return um[s.substr(0, 2)] + romanToInt(s.substr(2));
        else
            return um[s.substr(0, 1)] + romanToInt(s.substr(1));
    }
};
