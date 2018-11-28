#include <iostream>
#include "json.hpp"
#include <fstream>

int main(int argc, const char * argv[]) {
    // insert code here...


	using json = nlohmann::json;

    int sketch_memory = 14000;

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


    /*std::cout << ATmega168p_memory << "\n";
    std::cout << ATmega328p_memory << "\n";
    std::cout << ATmega644p_memory << "\n";
    std::cout << ATmega1284_memory << "\n";
    std::cout << ATmega2560_memory << "\n";

    std::cout << ATtiny3217_memory << "\n";
    std::cout << ATtiny1617_memory << "\n";
    std::cout << ATtiny817_memory << "\n";*/

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

    for(int i = 0; i < arraySize; i++){
        std::cout << memory_array[i] << "\n";
    }



    return 0;
}