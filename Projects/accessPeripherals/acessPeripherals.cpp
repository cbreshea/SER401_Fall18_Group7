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

    /*for(int i = 0; i < megaAvr["MegaAVRs"].size(); ++i){
      temp1 = megaAvr["MegaAVRs"][i]["Digital Communication Peripherals"].size();//this assignment is needed to convert to c++ int
      cout << temp1 << endl;
      
    }


    for(int i = 0; i < tinyAvr["TinyAVRs"].size(); ++i){
      temp2 = tinyAvr["TinyAVRs"][i]["Digital Communication Peripherals"].size();//this assignment is needed to convert to c++ int
      cout << temp2 << endl;
      
    }


    // access each one
    cout << " " << endl;
    int size = 3;
    for(int i = 0; i < megaAvr["MegaAVRs"].size(); ++i){
      for(int j = 0; j < 3; j++){
      	cout << megaAvr["MegaAVRs"][i]["Digital Communication Peripherals"][j] << endl;
      }
      cout << " " <<endl;
    }*/

    cout << " " << endl;
    int size = 3;
    for(int i = 0; i < megaAvr["MegaAVRs"].size(); ++i){
      
      cout << megaAvr["MegaAVRs"][i]["Number of UART"] << endl;
      
      cout << " " <<endl;
    }





    return 0;
}