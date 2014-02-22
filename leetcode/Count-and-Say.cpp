class Solution {
public:
    string countAndSay(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string result = "1";
        while(n-- > 1)
        {
            string temp;
            while(!result.empty())
            {
                int count = 1;
                if(result.size() >= 3 && result[0] == result[1] && result[0] == result[2]) 
                    count = 3;
                else if(result.size() >= 2 && result[0] == result[1]) 
                    count = 2;
                    
                temp += string(1, count + '0') + result[0];
                result = result.substr(count);
            }//while
            
            result = temp;
        }
        
        return result;
    }
};

// alternative
class Solution {
public:
    string countAndSay(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n == 1) return "1";

        string init = "11";

        while(n-- > 2)
        {
            string next;
            int count = 1;
            for(int i=0; i<init.size(); i++)
            {
                if(init[i+1] == init[i]) 
                    count++;
                else
                {
                    char c = ('0'+count);
                    next = next + c + init[i];
                    count = 1;
                }            
            }
            init = next;
        }

        return init;

    }
};
