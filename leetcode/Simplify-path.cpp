class Solution {
public:
    string simplifyPath(string path) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string sp; // simplified path
        
        int pos = path.find('/');
        while(pos != string::npos)
        {
            string part = path.substr(0, pos);
            
            if(part == "..") 
                sp = sp.substr(0, sp.find_last_of('/'));
            else if(part != "." && path != "/" && !part.empty())
                sp += "/" + part;
                
            path = path.substr(pos+1);
            pos = path.find('/');
        }
        
        if(path == "..")
        {
            sp = sp.substr(0, sp.find_last_of('/'));
        }
        else if(!path.empty() && path != ".")
            sp += "/" + path;
            
        return sp.empty() ? "/" : sp;
    }
};

// alternative
class Solution {
public:
    string simplifyPath(string path) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<string> ps;
        
        for(int i=0; i<path.size();)
        {
            if( path[i] == ' ') i++;
            else if( path[i] == '/')
            {
                // find next '/' and check the string between '/'
                int j=i+1;
                while(j<path.size() && path[j] != '/') j++;
                string temp = path.substr(i+1, j-i-1);
                
                if(temp.empty() || temp.compare(".") == 0) 
                    ; //ignore
                else if(temp.compare("..") == 0) 
                {
                    if(!ps.empty()) ps.pop();
                }
                else
                {
                    ps.push(temp);
                }
                
                // reset i
                i = j;
            }
        }//while
        
        string result;
        while(!ps.empty())
        {
            if(result.empty())
                result = ps.top();
            else
                result = ps.top() + "/" + result;
                
            ps.pop();
        }
        
        return "/" + result;
    }
};
