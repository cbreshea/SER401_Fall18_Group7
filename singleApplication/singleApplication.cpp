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
#define PIN_COUNT_PERCENT_BUFFER 10

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
   string tempMem;
   int num;
   //while end of stream has not been reached
   while(!ss.eof()){
      ss >> tempMem;//get word from stream
      if(stringstream(tempMem) >> num){//if an int
         return num;
      }
      tempMem = "";
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
method to recommend a microcontroller from json files that the program will work on. memReq is expected to be the size of the project expected to
be put on the microcontroller and is expected to represent the number of bytes. pinReq is the number of pins required by the program
*/
string recommendMicroController(int memReq, int pinReq){
   string mcName = "None";
   //open json files
   using json = nlohmann::json;
    std::ifstream mega("MegaAVR.json");
    std::ifstream tiny("TinyAVR.json");
   //read json objects from json files
    json megaAvr = json::parse(mega);
    json tinyAvr = json::parse(tiny);
    
    int sizeRec = std::numeric_limits<int>::max();//set initial size recommendation to a high number so the first size checked will always be picked
    int pinCountRec = std::numeric_limits<int>::max();//set initial size recommendation to a high number so the first size checked will always be picked
    int tempMem = 0;//variable to hold memory from microcontroller
    int tempPinCount = 0;//variable to hold pin count from microcontroller
    json microcontroller;
   
    for(int i = 0; i < megaAvr["MegaAVRs"].size(); ++i){
      tempMem = megaAvr["MegaAVRs"][i]["Program Memory Size(KB)"];//this assignment is needed to convert to c++ int
      tempPinCount = megaAvr["MegaAVRs"][i]["Pin Count"];//this assignment is needed to convert to c++ int
      tempMem = tempMem * 1000;//convert from KB to bytes
      if( (memReq < tempMem) && (pinReq < tempPinCount) ){//if program will fit in memory and pin count
         if( (tempMem <= sizeRec) && (tempPinCount <= pinCountRec) ){//if microcontroller memory size and pin count are smaller than previously selected memory size and pin count
            sizeRec = tempMem;//recommend memory size
            pinCountRec = tempPinCount;//recommend pin count
            mcName = megaAvr["MegaAVRs"][i]["Name"];//recommend microcontroller
         }
      }
    }
   
    for(int i = 0; i < tinyAvr["TinyAVRs"].size(); ++i){
      tempMem = tinyAvr["TinyAVRs"][i]["Program Memory Size(KB)"];//this assignment is needed to convert to c++ int
      tempPinCount = tinyAvr["TinyAVRs"][i]["Pin Count"];//this assignment is needed to convert to c++ int
      tempMem = tempMem * 1000;//convert from KB to bytes
      if( (memReq < tempMem) && (pinReq < tempPinCount) ){//if program will fit in memory and in count
         if( (tempMem <= sizeRec) && (tempPinCount <= pinCountRec) ){//if memory size and pin count are smaller than previously selected memory size and pin count
            sizeRec = tempMem;//recommend memory size
            pinCountRec = tempPinCount;//recommend pin count
            mcName = tinyAvr["TinyAVRs"][i]["Name"];//recommend microcontroller
         }
      }
    }
    //check if program size is close to program memory for microcontroller, if it is then bump it up to next recommendation
    //by using the previous recommending microcontroller program memory as a requirement
    if( percentChange(sizeRec, memReq) <= MEMORY_PERCENT_BUFFER ){
      mcName = recommendMicroController(sizeRec, pinReq);
    }//if pin count is within buffer range then bump up to next available pin count by using recommendation as requirement for new recommendation
    else if(percentChange(pinCountRec, pinReq) <= PIN_COUNT_PERCENT_BUFFER){
      mcName = recommendMicroController(memReq, pinCountRec);
    }
    return mcName;
}

string[] getLibraries(string fileName){
   string word;
	bool isLibrary = false;
	ifstream inFile;
   string[] libraries = [];

	//inFile.open(filePath);
	inFile.open(fileName);
	//inFile.open("D:\\IDE Workspaces\\test\\src\\test.cpp");
	//D:\IDE Workspaces\test\src\test.cpp

	if (!inFile) {//file could not be opened
	    cout << "There was an issue opening the file";
	    exit(1);
	}

	while (inFile >> word) {
		if (isLibrary){
		word = word.substr(1, word.size() - 2);//get library name
			libraries = addStringToArray(libraries, word);//add library to array
			isLibrary = false;
		}
		if (word.compare("#include") == 0){
			isLibrary = true;//library found
		}
	}
	inFile.close();
   return libraries;
}

//function to add a string to an array
string[] addStringToArray(string[] array, string item){
   string[] newArray = [array.size() + 1];//create array with size for one more string
   int i;
   //copy elements from old array to new array
   for(i = 0; i < array.size(); i++){
      newArray[i] = array[i];
   }
   newArray[newArray.size() - 1] = item//add item to end of array
   return newArray
}

int main(int argc, const char ** argv) {
    
    if(argc > 1){//if a filename has been given
    string str = "";
    //get name of file to compile and measure
    str = str + argv[1];
    string str2 = "";
    str2 = str2 + argv[2];
    //compile arduino sketch using the arduino cli, capturing stdout in string output
    //string output = GetStdoutFromCommand( ("cd ./example && arduinocli compile -b arduino:avr:uno " + str + " -o main").c_str() );
    int size = stoi(str);//get file size from arduinocli output
    int pinCount = stoi(str2);
    string microcontroller = recommendMicroController(size, pinCount);//get recommended microcontroller for program size
    //output program measured, program size, and name of recommended microcontroller
    cout << "Program: " << str << endl;
    cout << "Size: " << size << " bytes" << endl;
    cout << "PinCount: " << pinCount << endl;
    cout << "Recommendation: " << microcontroller << endl;
    }
    else{
      cout << "Please enter a filename.";
    }
    return 0;
}




