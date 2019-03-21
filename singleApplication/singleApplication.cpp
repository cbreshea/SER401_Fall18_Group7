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

#define MEMORY_PERCENT_BUFFER 10

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

//function to find percent change between two integers
// formula: ( (num2 - num1)/abs(num1) ) * 100
int percentChange(int num1, int num2){
	double difference = abs(num2-num1);
	double initial_quotient = abs(num1);
	double final_quotient = difference/initial_quotient;
	int percent = final_quotient*100;
	return percent;
}

/*
method to recommend a microcontroller from json files that the program will fit on. memReq is expected to be the size of the project expected to
be put on the microcontroller and is expected to represent the number of bytes.
*/
string recommendMicroController(int memReq){
   string mcName = "None";
   //open json files
   using json = nlohmann::json;
    std::ifstream mega("MegaAVR.json");
    std::ifstream tiny("TinyAVR.json");
   //read json objects from json files
    json megaAvr = json::parse(mega);
    json tinyAvr = json::parse(tiny);
    
    int sizeRec = std::numeric_limits<int>::max();//set initial size recommendation to a high number so the first size checked will always be picked
    int temp = 0;//variable to hold memory from microcontroller
    json microcontroller;
   
    for(int i = 0; i < megaAvr["MegaAVRs"].size(); ++i){
      temp = megaAvr["MegaAVRs"][i]["Program Memory Size(KB)"];//this assignment is needed to convert to c++ int
      if( memReq < (temp * 1000) ){//if program will fit in memory
         if( temp < sizeRec){//if memory size is smaller than previously selected memory size
            sizeRec = temp;//recommend memory size
            mcName = megaAvr["MegaAVRs"][i]["Name"];//recommend microcontroller
         }
      }
    }
   
    for(int i = 0; i < tinyAvr["TinyAVRs"].size(); ++i){
      temp = tinyAvr["TinyAVRs"][i]["Program Memory Size(KB)"];//this assignment is needed to convert to c++ int
      if( memReq < (temp * 1000) ){//if program will fit in memory
         if( temp < sizeRec){//if memory size is smaller than previously selected memory size
            sizeRec = temp;//recommend memory size
            mcName = tinyAvr["TinyAVRs"][i]["Name"];//recommend microcontroller
         }
      }
    }
    sizeRec = sizeRec * 1000;//convert from KB to bytes
    //check if program size is close to program memory for microcontroller, if it is then bump it up to next recommendation
    //by using the previous recommending microcontroller program memory as a requirement
    if( percentChange(sizeRec, memReq) <= MEMORY_PERCENT_BUFFER ){
      mcName = recommendMicroController(sizeRec);
    }
    
    return mcName;
}

int main(int argc, const char ** argv) {
    
    if(argc > 1){//if a filename has been given
    string str = "";
    //get name of file to compile and measure
    str = str + argv[1];
    //compile arduino sketch using the arduino cli, capturing stdout in string output
    string output = GetStdoutFromCommand( ("cd ./example && arduinocli compile -b arduino:avr:uno " + str + " -o main").c_str() );
    int size = GetIntFromString(output);//get file size from arduinocli output
    string microcontroller = recommendMicroController(size);//get recommended microcontroller for program size
    //output program measured, program size, and name of recommended microcontroller
    cout << "Program: " << str << endl;
    cout << "Size: " << size << " bytes" << endl;
    cout << "Recommend: " << microcontroller << endl;
    }
    else{
      cout << "Please enter a filename.";
    }
    return 0;
}




