
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

int main(void) {
    string line;
    int count;
    string word = "PIN";
    string randomBoard = "ATMEGA4609";
    ifstream file("simple.ino");
    char ch[40];
    if (file.is_open()){ // This is when the file is open go through the file
        while(getline(file,line)){ // This will go line by line
            if(line.starts_with('/*')){
                // it will go through and stop once there is a '*/'
                if (line.starts_with('*/')){
                   if (line.starts_with('*/'))continue;
                }
            }
            // now count the number of instances the word occurs
            while (file) {
                file >> word;
                //error with strcmp() suggest removing it and using another algorithm
                if(strcmp(ch, word)==0) // we are doing a string comparison
                    count++;
               
            }
        }
        cout << "Number of pins used is " << count << endl;
        cout << "The recommended board is: " << randomBoard << endl;
        file.close();
    }
}


