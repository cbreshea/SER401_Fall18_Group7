#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream file("sprint8test.txt");
    string line;
    while (getline(file, line))
    {
        
        if (line[0] == '/*') continue;

        // other stuff will come in here
    }
}