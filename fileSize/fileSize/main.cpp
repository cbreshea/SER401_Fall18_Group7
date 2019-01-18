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
#include <string>
using namespace std;

// returns size
/*
std::ifstream::pos_type filesize(const char* file)
{
    std::ifstream input(file, std::ifstream::ate | std::ifstream::binary);
    return input.tellg();
}
*/

int main(int argc, const char ** argv) {
    
    if(argc > 1){//if a filename has been given
    string str = "";
    //get name of file to compile and measure
    str = str + argv[1];
    //compile arduino sketch using the arduino cli
    system( ("cd ./example && arduinocli compile -b arduino:avr:uno " + str + " -o main").c_str() );
    //system(("arduinocli compile -b arduino:avr:uno Blink.ino -o main"));
    // Read example hex file given
    //cout << filesize(argv[1]) << " bytes" << std::endl;
    }
    else{
      //cout << "Please enter a filename.";
    }
    return 0;
}

