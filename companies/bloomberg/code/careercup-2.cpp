#include <iostream>

using namespace std;

void indexOfRuns(string input)
{
    if(input.empty()) return;
    
    int i = 0;
    while(i < input.size())
    {
        if(i+1 < input.size() && input[i] == input[i+1])
        {
            cout << i << " ";
            while(i+1 < input.size() && input[i] == input[i+1])
                ++i;
        }
        else
            i++;
    }

    cout << endl;
}

int main(int argc, char *argv[])
{
    string input = "abbbbbcc";
    if(argc == 2)
        input = argv[1];

    indexOfRuns(input);
    return 0;
}
