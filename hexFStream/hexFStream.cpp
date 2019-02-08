#include <sstream>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


/*Program that reads hex values using modfifier. 
Hex modifer will potentially be utilized to read hex files*/

int main(int argc, const char ** argv) {
    
    
    const char *filename = "hex.txt";
    ifstream infile(filename, fstream::in);

    unsigned int val;
    infile >> hex >> val; // read hex value
    cout << hex << val; // display hex value

    return 0;
}
