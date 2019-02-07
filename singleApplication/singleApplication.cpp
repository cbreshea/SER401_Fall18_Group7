//
//  main.cpp
//  fileSize
//
//  Created by Stoiev Caneda on 11/14/18.
//  Copyright © 2018 Stoiev Caneda. All rights reserved.
//
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "json.hpp"
#include <math.h>
#include <limits>
#include <string>
using namespace std;

/*
IMPORTANT NOTE:
There seems to be a compatability issue between the -std=c++11 compiler option and the system commands used in GetStdoutFromCommand. 
This option is needed in order to allow use of json.hpp to be used in this program. In order to maintain compatability instead use
the compiler option -std=gnu++11 for the program to successfully compile.
*/

// returns size
/*
std::ifstream::pos_type filesize(const char* file)
{
    std::ifstream input(file, std::ifstream::ate | std::ifstream::binary);
    return input.tellg();
}
*/

/*
function for capturing stdout and stderr from a system command and returning it as a string.
retrieved from: https://www.jeremymorgan.com/tutorials/c-programming/how-to-capture-the-output-of-a-linux-command-in-c/
*/
string GetStdoutFromCommand(string cmd) {
    string data;
    FILE * stream;
    const int max_buffer = 256;//buffer size
    char buffer[max_buffer];//create buffer
    cmd.append(" 2>&1");//combine stderr and stdout

    stream = popen(cmd.c_str(), "r");//run command
    if (stream) {
    while (!feof(stream))//while there is data in stream
    if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);//null pointer check if what is read is eof, add data read to string to return
    pclose(stream);//close stream
    }
    return data;//return output
}

//retrieves first int found in string 
int GetIntFromString(string str){
   stringstream ss;
   ss << str;//put string is stringstream
   string temp;
   int num;
   //while end of stream has not been reached
   while(!ss.eof()){
      ss >> temp;//get word from stream
      if(stringstream(temp) >> num){//if an int
         return num;
      }
      temp = "";
   }
}

/*
method to recommend a microcontroller from json files that the program will fit on. memReq is expected to be the size of the project expected to
be put on the microcontroller and is expected to represent the number of bytes.
*/
string recommendMicroController(int memReq){
   //open json files
   using json = nlohmann::json;
    std::ifstream mega("MegaAVR.json");
    std::ifstream tiny("TinyAVR.json");
   //read objects from json files
    json megaAvr = json::parse(mega);
    json tinyAvr = json::parse(tiny);
    
    memReq = 10000;
    int sizeRec = std::numeric_limits<int>::max();//set initial size recommendation to a high number so the first size checked will always be picked
    int temp = 0;//variable to hold memory from microcontroller
    json microcontroller;
   
    for(int i = 0; i < megaAvr["MegaAVRs"].size(); ++i){
      temp = megaAvr["MegaAVRs"][i]["Program Memory Size(KB)"];//this assignment is needed to convert to c++ int
      if( memReq < (temp * 1000) ){//if program will fit in memory
         if( temp < sizeRec){//if memory size is smaller than previously selected memory size
            sizeRec = temp;//recommend memory size
            microcontroller = megaAvr["MegaAVRs"][i];//recommend microcontroller
         }
      }
    }
   
    for(int i = 0; i < tinyAvr["TinyAVRs"].size(); ++i){
      temp = tinyAvr["TinyAVRs"][i]["Program Memory Size(KB)"];//this assignment is needed to convert to c++ int
      if( memReq < (temp * 1000) ){//if program will fit in memory
         if( temp < sizeRec){//if memory size is smaller than previously selected memory size
            sizeRec = temp;//recommend memory size
            microcontroller = tinyAvr["TinyAVRs"][i];//recommend microcontroller
         }
      }
    }
    
    return microcontroller["Name"];
}

int main(int argc, const char ** argv) {
    
    if(argc > 1){//if a filename has been given
    string str = "";
    //get name of file to compile and measure
    str = str + argv[1];
    //compile arduino sketch using the arduino cli, capturing stdout in string output
    string output = GetStdoutFromCommand( ("cd ./example && arduinocli compile -b arduino:avr:uno " + str + " -o main").c_str() );
    int size = GetIntFromString(output);//get file size from arduinocli output
    //output file size
    cout << "Program: " << str << endl;
    cout << "Size: " << size << " bytes";
    }
    else{
      cout << "Please enter a filename.";
    }
    return 0;
}



