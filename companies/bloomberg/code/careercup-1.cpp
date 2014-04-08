#include <iostream>

using namespace std;

string longestRun(string input)
{
    if(input.empty()) return string();
    
    char c = input[0], tc = input[0];
    int len = 1, tlen = 1;

    for(int i=1; i<input.size(); i++)
    {
        if(input[i] == input[i-1]) ++tlen;
        else
        {
            if(tlen > len)
            {
                len = tlen;
                c = tc;
            }

            tlen = 1;
            tc = input[i];
        }
    }

    return (tlen > len) ? string(tlen, tc) :  string(len, c);
}

int main(int argc, char *argv[])
{
    string input = "abbbbbcc";
    if(argc == 2)
        input = argv[1];

    cout << "longest run: " << longestRun(input) << endl;
    return 0;
}
