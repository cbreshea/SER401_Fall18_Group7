#include <fstream>
#include <iostream>
#include <string>
#include "json.hpp"

int main(int argc, const char * argv[]){
	
	
	using json = nlohmann::json;
	std::ifstream i("Neopixel.json");
	json j = json::parse(i);

	json Neopixel = j["Neopixel"];
    json Neopixel = j["Black 30 LED 1m"];
		
	int Black_LED_30_1m = Neopixel["Black LED 30 1m"];
    
    std::cout << Black_LED_30_1m;
    
					
	}
	
	
	
