
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void) {
    string line;
    int count;
    string word = "PinMode";
    string randomBoard = "ATMEGA4609";
    ifstream file("cat.txt");
    char ch[40] , c [40];
    if (file.is_open()){
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
                if(strcmp(ch, word)==0)
                    count++;
               
            }
        }
        cout << "Number of pins used is " << count << endl;
        cout << "The recommended board is: " << randomBoard << endl;
        file.close();
    }
}
