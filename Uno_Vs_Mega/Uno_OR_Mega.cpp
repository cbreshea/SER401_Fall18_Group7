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
	
	
	int Arduino_Uno_Rev3_SMD_Apins = Arduino_Uno_Rev3_SMD["Analog Input Pins"];
	int Arduino_Uno_Wifi_Rev2_Apins = Arduino_Uno_Wifi_Rev2["Analog Input Pins"];
	
	/*
	Since I am not reading in a hex file just yet I am just going to
	ask the user for the information on the project and then determine
	the best board to use.
	*/
	
	//get the user info 
	
	//Pins
	int digitalPins;
	int analogPins;
	std::cout << "How many Digital pins does your project use?";
	std::cin >> digitalPins;
	std::cout << "How many analog pins does your project use?";
	std::cin >> analogPins;
	
	//Amount of memory
	int memory;
	std::cout << "How much memory does the project use?";
	std::cin >> memory;
	
	//SRAM and EEPROM
	int sram;
	int eeprom;
	
	std::cout << "Amount of SRAM?";
	std::cin >> sram;
	std::cout << "amount of EEPROM?";
	std::cin >> eeprom;
	
	/*
	Here we are just going to take the users input and loop through 
	to determine what the best board to use is. 
	This will be determined by measuring the amount of digital/analog pins the user is using in their project
	*/
	
	if(digitalPins > 14 || analogPins > 6){
		std::cout << "After running analysis on your project it has been determined that you use the Arduino Mega 2560 Rev3";
						}else if(digitalPins < 14 || analogPins < 6){
		std::cout << "After running analysis on your project it has been determined that you use the Arduino Uno Rev3";
					
	}
	
	
	//std::cout << Arduino_Mega_2560_Rev3_pins << "\n";
	
	
}
