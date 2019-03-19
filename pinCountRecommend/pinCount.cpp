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

#define PIN_PERCENT_BUFFER 10

/*
IMPORTANT NOTE:
There seems to be a compatability issue between the -std=c++11 compiler option and the system commands used in GetStdoutFromCommand. 
This option is needed in order to allow use of json.hpp to be used in this program. In order to maintain compatability instead use
the compiler option -std=gnu++11 for the program to successfully compile.
*/

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
method to recommend a microcontroller from json files that the program will work on. pinReq is the number of pins required by a project.
*/
string recommendMicroController(int pinReq){
   string mcName = "None";
   //open json files
   using json = nlohmann::json;
    std::ifstream mega("MegaAVR.json");
    std::ifstream tiny("TinyAVR.json");
   //read json objects from json files
    json megaAvr = json::parse(mega);
    json tinyAvr = json::parse(tiny);
    
    int pinRec = std::numeric_limits<int>::max();//set initial pin count recommendation to a high number so the first pin count checked will always be picked
    int temp = 0;//variable to hold pin count from microcontroller
    json microcontroller;
   
    for(int i = 0; i < megaAvr["MegaAVRs"].size(); ++i){
      temp = megaAvr["MegaAVRs"][i]["Pin Count"];//this assignment is needed to convert to c++ int
      if( pinReq < temp ){//pin requirement is less than pin count of microcontroller
         if( temp < pinRec){//if pin count is smaller than previously selected pin count
            pinRec = temp;//recommend pin count
            mcName = megaAvr["MegaAVRs"][i]["Name"];//recommend microcontroller
         }
      }
    }
   
    for(int i = 0; i < tinyAvr["TinyAVRs"].size(); ++i){
      temp = tinyAvr["TinyAVRs"][i]["Pin Count"];//this assignment is needed to convert to c++ int
      if( pinReq < temp ){//pin requirement is less than pin count of microcontroller
         if( temp < pinRec){//if pin count is smaller than previously selected pin count
            pinRec = temp;//recommend pin count
            mcName = tinyAvr["TinyAVRs"][i]["Name"];//recommend microcontroller
         }
      }
    }
    //check if program pin requirement is close to pin count for microcontroller, if it is then bump it up to next recommendation
    //by using the previous recommended microcontroller pin count as a requirement
    if( percentChange(pinRec, pinReq) <= PIN_PERCENT_BUFFER ){
      mcName = recommendMicroController(pinRec);
    }
    
    return mcName;
}

int main(int argc, const char ** argv) {
    
    if(argc > 1){//if a pin count has been given
    string str = "";
    str = str + argv[1];//get pin count given
    int count = stoi(str);//convert to int
    string microcontroller = recommendMicroController(count);//get recommended microcontroller for program size
    //output program measured, program size, and name of recommended microcontroller
    cout << "requested pin count: " << count << endl;
    cout << "Recommend: " << microcontroller << endl;
    }
    else{
      cout << "Please enter a filename.";
    }
    return 0;
}

