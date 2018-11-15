//
//  main.cpp
//  fileSize
//
//  Created by Stoiev Caneda on 11/14/18.
//  Copyright © 2018 Stoiev Caneda. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

// returns size
std::ifstream::pos_type filesize(const char* file)
{
    std::ifstream input(file, std::ifstream::ate | std::ifstream::binary);
    return input.tellg();
}


int main(int argc, const char * argv[]) {
    // insert code here..
    
    // Read example hex file given
    cout << filesize("FastLEDRainbow.ino.standard.hex") << " bytes" << std::endl;
    return 0;
}

