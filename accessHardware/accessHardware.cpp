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
    std::ifstream hardware("librariesHardware.json");
   
    json hard = json::parse(hardware);

    std::string temp = "";//variable to hold pin count from microcontroller

    cout << "Libraries" << endl;

    for(int i = 0; i < hard["Libraries"].size(); ++i){
      temp = hard["Libraries"][i]["name"];//this assignment is needed to convert to c++ int
      cout << temp << endl;
      
    }
    
    for(int i = 0; i < hard["Libraries"].size(); ++i){
      temp = hard["Libraries"][i]["Requires"][0];//this assignment is needed to convert to c++ int
      cout << temp << endl;
      
    }




    return 0;
}