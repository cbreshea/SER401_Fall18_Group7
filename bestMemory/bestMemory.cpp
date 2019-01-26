#include <sstream>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "json.hpp"
#include <math.h>
using namespace std;


// returns size

std::ifstream::pos_type filesize(const char* file)
{
    std::ifstream input(file, std::ifstream::ate | std::ifstream::binary);
    return input.tellg();
}

int min(int *arr, int num);
void recommend(int num, int *arr);
int percentDifference(int num1, int num2);
bool checkDifference(int sketch_mem, int chip_mem);

int main(int argc, const char * argv[]) {
    
    if(argc > 1){
    // Read example hex file given
    cout << filesize(argv[1]) << " bytes" << std::endl;
    }
    else{
      cout << "Please enter a filename.";
    }

    int sketch = filesize(argv[1]);
    using json = nlohmann::json;

    std::ifstream i("MegaAVR.json");
    std::ifstream a("TinyAVR.json");
    json j = json::parse(i);
    json b = json::parse(a);

    // MegaAVRs
    json ATmega168p = j["ATmega168p"];
    json ATmega328p = j["ATmega328p"];
    json ATmega644p = j["ATmega644p"];
    json ATmega1284 = j["ATmega1284"];
    json ATmega2560 = j["ATmega2560"];

    //TinyAVRS
    json ATtiny3217 = b["ATtiny3217"];
    json ATtiny1617 = b["ATtiny1617"];
    json ATtiny817 = b["ATtiny817"];

    
  
    int ATmega168p_kb = ATmega168p["Program Memory Size(KB)"];
    int ATmega328p_kb = ATmega328p["Program Memory Size(KB)"];
    int ATmega644p_kb = ATmega644p["Program Memory Size(KB)"];
    int ATmega1284_kb = ATmega1284["Program Memory Size(KB)"];
    int ATmega2560_kb = ATmega2560["Program Memory Size(KB)"];

    int ATtiny3217_kb = ATtiny3217["Program Memory Size(KB)"];
    int ATtiny1617_kb = ATtiny1617["Program Memory Size(KB)"];
    int ATtiny817_kb = ATtiny817["Program Memory Size(KB)"];

    int ATmega168p_memory =  ATmega168p_kb * 1000;
    int ATmega328p_memory = ATmega328p_kb * 1000;
    int ATmega644p_memory = ATmega644p_kb * 1000;
    int ATmega1284_memory = ATmega1284_kb * 1000;
    int ATmega2560_memory = ATmega2560_kb * 1000;

    int ATtiny3217_memory = ATtiny3217_kb * 1000;
    int ATtiny1617_memory = ATtiny1617_kb * 1000;
    int ATtiny817_memory = ATtiny817_kb * 1000;


    int memory_array[8];
    int arraySize = 8;

    memory_array[0] = ATmega168p_memory;
    memory_array[1] = ATmega328p_memory;
    memory_array[2] = ATmega644p_memory;
    memory_array[3] = ATmega1284_memory;
    memory_array[4] = ATmega2560_memory;
    memory_array[5] = ATtiny3217_memory;
    memory_array[6] = ATtiny1617_memory;
    memory_array[7] = ATtiny817_memory;

    std::cout << "The microchip is: ";
    recommend(sketch, memory_array);

    return 0;


}



// find the smallest difference between sketch memory and available. This is to find the closest chip with the memory capacity 
int min(int *arr, int num){

    int diff[8];
    int sum = 0;

    for(int i = 0; i < 8; i++){
        sum = arr[i] - num;
        // check if the difference is positive. This means the chip has the memory capacity 
        if(sum >= 0){
            diff[i] = sum;
        }else{
            diff[i] = -1;
        }
    }

    int flag = 0;
    int smallest = 2147483647; // largest int value

    for(int i = 0; i < 8; i++){
        if(diff[i] < smallest && diff[i] > 0){
            smallest = diff[i]; 
            flag = 1; // a postive min was found
        }
    }

    if(flag == 1){
        return smallest;
    }else{
        return -1;
    }

}

void recommend(int size, int *arr){

    // hash map to match microchip name (key) and its memory(value)
    std::map<std::string, int> m;
    m["Atmega168p"] = arr[0];
    m["ATmega328p"] = arr[1];
    m["ATmega644p"] = arr[2];
    m["ATmega1284"] = arr[3];
    m["ATmega2560"] = arr[4];
    m["ATtiny3217"] = arr[5];
    m["ATtiny1617"] = arr[6];
    m["ATtiny817"] = arr[7];

    std::cout << " "<< "\n";

    std::string chip;

    if(min(arr, size) == -1){
        std::cout << "no chip meets requirements" << "\n";
    }else{
        for (auto const& x : m)
        {
            if(x.second == (size+min(arr, size))){

                chip = x.first;
            }
   
        }

        std::cout << chip << "\n";
    }

    

}

int percentDifference(int num1, iny num2){
	int difference = num1-num2;
	int sum = num1 + num2;
	int initial_quotient = sum/2;
	int final_quotient = difference/initial_quotient;
	int percent = final_quotient*100;
	return percent;
}

// check if the sketch memory is close to memory capacity through the percent difference 
bool checkDifference(int sketch_mem, int chip_mem){
    int diff = percentDifference(sketch_mem, chip_mem);

    if(diff <= 10 && diff >= 10){
        return true;
    }else{
        return false;
    }
}



