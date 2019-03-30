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

int main(int argc, const char ** argv) {
    
    using json = nlohmann::json;
    std::ifstream mega("MegaAVR.json");
    std::ifstream tiny("TinyAVR.json");

	  json megaAvr = json::parse(mega);
	  json tinyAvr = json::parse(tiny);

    json temp1 = 0;//variable to hold peripheral info from microcontroller
    json temp2 = 0;//variable to hold peripheral info from microcontroller

    for(int i = 0; i < megaAvr["MegaAVRs"].size(); ++i){
      temp = megaAvr["MegaAVRs"][i]["Digital Communication Peripherals"];//this assignment is needed to convert to c++ int
      cout << temp1 << endl;
      
    }


    for(int i = 0; i < tinyAvr["TinyAVRs"].size(); ++i){
      temp = tinyAvr["TinyAVRs"][i]["Digital Communication Peripherals"];//this assignment is needed to convert to c++ int
      cout << temp2 << endl;
      
    }

    return 0;
}