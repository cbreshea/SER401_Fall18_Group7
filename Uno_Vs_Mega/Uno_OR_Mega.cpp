#include <fstream>
#include <iostream>
#include <string>
#include "json.hpp"

int main(int argc, const char * argv[]){
	
	int tempProject = 14;
	
	using json = nlohmann::json;
	//JSON file for Arduino Boards
	std::ifstream i("Arduino_Boards.json");
	json j = json::parse(i);
	
	//Arduino Boards
	json Arduino_Mega_2560_Rev3 = j["Arduino_Mega_2560_Rev3"];
	json Arduino_Uno_Rev3 = j["Arduino_Uno_Rev3"];
	json Arduino_Uno_Rev3_SMD = j["Arduino_Uno_Rev3_SMD"];
	json Arduino_Uno_Wifi_Rev2 = j["Arduino_Uno_Wifi_Rev2"];
	
	
	int Arduino_Mega_2560_Rev3_pins = Arduino_Mega_2560_Rev3["Digital I/O Pins"];
	int Arduino_Uno_Rev3_pins = Arduino_Uno_Rev3["Digital I/O Pins"];
	int Arduino_Uno_Rev3_SMD_pins = Arduino_Uno_Rev3_SMD["Digital I/O Pins"];
	int Arduino_Uno_Wifi_Rev2_pins = Arduino_Uno_Wifi_Rev2["Digital I/O Pins"];
	
	
	std::cout << "Lets assume the users project is using 14 digital I/O pins is using 14 pins but";
	std::cout << "they are using an Arduino Mega 2560 with too many unused digital pins";
	//std::cout << Arduino_Mega_2560_Rev3_pins << "\n";
	
	
}
