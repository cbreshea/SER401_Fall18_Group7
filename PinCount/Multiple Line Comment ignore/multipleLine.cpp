#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void) {
    string line;
    ifstream file("cat.txt");
    if (file.is_open()){
        while(getline(file,line)){ // This will go line by line
            if(line.starts_with('/*')){
                // it will go through and stop once there is a '*/'
            }
        }
        
        file.close();
    }
