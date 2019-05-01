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

    // using 
    int UART_REQ = 2;
    int SPI_REQ = 3;
    int I2C_REQ = 1;

    int UART_REC = std::numeric_limits<int>::max();
    int SPI_REC = std::numeric_limits<int>::max();
    int I2C_REC = std::numeric_limits<int>::max();

    int tempUART = 0;
    int tempSPI = 0;
    int tempI2C = 0;

    string mcName = "None";

    

    for(int i = 0; i < megaAvr["MegaAVRs"].size(); ++i){
      tempUART = megaAvr["MegaAVRs"][i]["Number of UART"];//this assignment is needed to convert to c++ int
      tempSPI = megaAvr["MegaAVRs"][i]["Number of SPI"];//this assignment is needed to convert to c++ int
      tempI2C = megaAvr["MegaAVRs"][i]["Number of I2C"];//this assignment is needed to convert to c++ int
      if( (UART_REQ <= tempUART) && (SPI_REQ <= tempSPI) && (I2C_REQ <= tempI2C) ){
         if((tempUART <= UART_REC) && (tempSPI <= UART_REC) && (tempI2C <= I2C_REC)){
             UART_REC = tempUART;
             SPI_REC = tempSPI;
             I2C_REC = tempI2C;
             mcName = megaAvr["MegaAVRs"][i]["Name"];//recommend microcontroller
         }
      }
    }

    cout << mcName << endl;




    return 0;
}