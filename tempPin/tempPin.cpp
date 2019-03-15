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

    json megaAvr = json::parse(mega);

    int temp = 0;//variable to hold pin count from microcontroller

    for(int i = 0; i < megaAvr["MegaAVRs"].size(); ++i){
      temp = megaAvr["MegaAVRs"][i]["Pin Count"];//this assignment is needed to convert to c++ int
      cout << temp << endl;
      
    }

    return 0;
}