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
      cout << megaAvr["MegaAVRs"][i]["Number of SPI"] << endl;
      cout << megaAvr["MegaAVRs"][i]["Number of I2C"] << endl;
      
      cout << " " <<endl;
    }

    int arr1[5];
    int arr2[5];
    int arr3[5];

    string chipNames[5];
    chipNames[0] = "ATmega168p";
    chipNames[1] = "ATmega328p";
    chipNames[2] = "ATmega644p";
    chipNames[3] = "ATmega1284";
    chipNames[4] = "ATmega2560";


    for(int i = 0; i < megaAvr["MegaAVRs"].size(); ++i){
      
      cout << chipNames[i] <<endl;

      arr1[i] = megaAvr["MegaAVRs"][i]["Number of UART"];
      arr2[i] = megaAvr["MegaAVRs"][i]["Number of SPI"];
      arr3[i] = megaAvr["MegaAVRs"][i]["Number of I2C"];
      
      
    }

    std::map<std::string, int> m;
    m["Atmega168pUART"] = arr1[0];
    m["Atmega168pSPI"] = arr2[0];
    m["Atmega168pI2C"] = arr3[0];

    m["Atmega328pUART"] = arr1[1];
    m["Atmega328pSPI"] = arr2[1];
    m["Atmega328pI2C"] = arr3[1];
    
    m["Atmega644pUART"] = arr1[2];
    m["Atmega644pSPI"] = arr2[2];
    m["Atmega644pI2C"] = arr3[2];

    m["Atmega1284pUART"] = arr1[3];
    m["Atmega1284pSPI"] = arr2[3];
    m["Atmega1284pI2C"] = arr3[3];

    m["Atmega2560UART"] = arr1[4];
    m["Atmega2560SPI"] = arr2[4];
    m["Atmega2560I2C"] = arr3[4];





    return 0;
}