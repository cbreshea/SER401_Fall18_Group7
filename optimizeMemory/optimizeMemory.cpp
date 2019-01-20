#include <iostream>
#include "json.hpp"
#include <fstream>
#include <math.h>

int min(int *arr, int num);
void recommend(int num, int *arr);
int sketch_memory = 128000;

int main(int argc, const char * argv[]) {
    // insert code here...


	using json = nlohmann::json;

   

	std::ifstream i("MegaAVR.json");
    //std::ifstream a("TinyAVR.json");
    json j = json::parse(i);
    //json b = json::parse(a);

    // MegaAVRs
    //json ATmega168p = j["ATmega168p"];
    json ATmega328p = j["ATmega328p"];
    json ATmega644p = j["ATmega644p"];
    json ATmega1284 = j["ATmega1284"];
    json ATmega2560 = j["ATmega2560"];
	json ATmega4809 = j["ATmega4809"];

    //TinyAVRS
    //json ATtiny3217 = b["ATtiny3217"];
    //json ATtiny1617 = b["ATtiny1617"];
    //json ATtiny817 = b["ATtiny817"];

    
  
    //int ATmega168p_kb = ATmega168p["Program Memory Size(KB)"];
    int ATmega328p_kb = ATmega328p["Program Memory Size(KB)"];
    int ATmega644p_kb = ATmega644p["Program Memory Size(KB)"];
    int ATmega1284_kb = ATmega1284["Program Memory Size(KB)"];
    int ATmega2560_kb = ATmega2560["Program Memory Size(KB)"];
	int ATmega4809_kb = ATmega4809["Program Memory Size(KB)"];

    //int ATtiny3217_kb = ATtiny3217["Program Memory Size(KB)"];
    //int ATtiny1617_kb = ATtiny1617["Program Memory Size(KB)"];
    //int ATtiny817_kb = ATtiny817["Program Memory Size(KB)"];

    //int ATmega168p_memory =  ATmega168p_kb * 1000;
    int ATmega328p_memory = ATmega328p_kb * 1000;
    int ATmega644p_memory = ATmega644p_kb * 1000;
    int ATmega1284_memory = ATmega1284_kb * 1000;
    int ATmega2560_memory = ATmega2560_kb * 1000;
	int ATmega4809_memory = ATmega4809_kb * 1000;

    //int ATtiny3217_memory = ATtiny3217_kb * 1000;
    //int ATtiny1617_memory = ATtiny1617_kb * 1000;
    //int ATtiny817_memory = ATtiny817_kb * 1000;


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

    //memory_array[0] = ATmega168p_memory;
    memory_array[1] = ATmega328p_memory;
    memory_array[2] = ATmega644p_memory;
    memory_array[3] = ATmega1284_memory;
    memory_array[4] = ATmega2560_memory;
	memory_array[5] = ATmega4809_memory;
    //memory_array[5] = ATtiny3217_memory;
    //memory_array[6] = ATtiny1617_memory;
    //memory_array[7] = ATtiny817_memory;

      std::cout << "The memory sizes of each chip" << "\n";

    for(int i = 0; i < arraySize; i++){
        std::cout << memory_array[i] << "\n";
    }

    int val = min(memory_array, sketch_memory);

    std::cout << " "<< "\n";


    std::cout << "The given memory is " << sketch_memory << " bytes, The smallest difference is : " << val << "\n";
   
 	
 	/*// hash map to match microchip name (key) and its memory(value)
    std::map<std::string, int> m;
    m["Atmega168p"] = ATmega168p_memory;
    m["ATmega328p"] = ATmega328p_memory;
    m["ATmega644p"] = ATmega644p_memory;
    m["ATmega1284"] = ATmega1284_memory;
    m["ATmega2560"] = ATmega2560_memory;
    m["ATtiny321"] = ATtiny3217_memory;
    m["ATtiny1617"] = ATtiny1617_memory;
    m["ATtiny817"] = ATtiny817_memory;

    
    for (auto const& x : m)
	{
    	std::cout << x.first  // string (key)
              << ':' 
              << x.second // string's value 
              << std::endl ;
	}

	std::cout << " "<< "\n";

	for (auto const& x : m)
	{
		if(x.second == (14000+val)){
			std::cout << x.first << std::endl;
		}
   
	}*/

    std::cout << "The microchip is: ";
    recommend(sketch_memory, memory_array);

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
    //m["Atmega168p"] = arr[0];
    m["ATmega328p"] = arr[1];
    m["ATmega644p"] = arr[2];
    m["ATmega1284"] = arr[3];
    m["ATmega2560"] = arr[4];
	m["ATmega4809"] = arr[4];
    //m["ATtiny3217"] = arr[5];
    //m["ATtiny1617"] = arr[6];
    //m["ATtiny817"] = arr[7];

	std::cout << " "<< "\n";

	std::string chip;

    if(min(arr, sketch_memory) == -1){
        std::cout << "no chip meets requirements" << "\n";
    }else{
        for (auto const& x : m)
        {
            if(x.second == (size+min(arr, sketch_memory))){

                chip = x.first;
            }
   
        }

        std::cout << chip << "\n";
    }

	

}


