//
//  main.cpp
//  fileSize
//
//
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "json.hpp"
#include <math.h>
#include <limits>
#include <string>
#include <vector>
using namespace std;

#define MEMORY_PERCENT_BUFFER 10
#define PIN_COUNT_PERCENT_BUFFER 10

/*
IMPORTANT NOTE:
There seems to be a compatability issue between the -std=c++11 compiler option and the system commands used in GetStdoutFromCommand. 
This option is needed in order to allow use of json.hpp to be used in this program. In order to maintain compatability instead use
the compiler option -std=gnu++11 for the program to successfully compile.
*/

// returns size
/*
std::ifstream::pos_type filesize(const char* file)
{
    std::ifstream input(file, std::ifstream::ate | std::ifstream::binary);
    return input.tellg();
}
*/

/*
function for capturing stdout and stderr from a system command and returning it as a string.
retrieved from: https://www.jeremymorgan.com/tutorials/c-programming/how-to-capture-the-output-of-a-linux-command-in-c/
*/
string GetStdoutFromCommand(string cmd) {
    string data;
    FILE * stream;
    const int max_buffer = 256;//buffer size
    char buffer[max_buffer];//create buffer
    cmd.append(" 2>&1");//combine stderr and stdout

    stream = popen(cmd.c_str(), "r");//run command
    if (stream) {
    while (!feof(stream))//while there is data in stream
    if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);//null pointer check if what is read is eof, add data read to string to return
    pclose(stream);//close stream
    }
    return data;//return output
}

//retrieves first int found in string 
int GetIntFromString(string str){
   stringstream ss;
   ss << str;//put string is stringstream
   string tempMem;
   int num;
   //while end of stream has not been reached
   while(!ss.eof()){
      ss >> tempMem;//get word from stream
      if(stringstream(tempMem) >> num){//if an int
         return num;
      }
      tempMem = "";
   }
}

//function to find percent change between two integers
// formula: ( (num2 - num1)/abs(num1) ) * 100
int percentChange(int num1, int num2){
	double difference = abs(num2-num1);
	double initial_quotient = abs(num1);
	double final_quotient = difference/initial_quotient;
	int percent = final_quotient*100;
	return percent;
}

/*
method to recommend a microcontroller from json files that the program will work on. memReq is expected to be the size of the project expected to
be put on the microcontroller and is expected to represent the number of bytes. pinReq is the number of pins required by the program
*/
string recommendMicroController(int memReq, int pinReq, vector<int> hardwareAmount){
   string mcName = "None";
   //open json files
   using json = nlohmann::json;
    std::ifstream mega("MegaAVR.json");
    std::ifstream tiny("TinyAVR.json");
   //read json objects from json files
    json megaAvr = json::parse(mega);
    json tinyAvr = json::parse(tiny);

    int sizeRec = std::numeric_limits<int>::max();//set initial size recommendation to a high number so the first size checked will always be picked
    int pinCountRec = std::numeric_limits<int>::max();//set initial size recommendation to a high number so the first size checked will always be picked
    int tempMem = 0;//variable to hold memory from microcontroller
    int tempPinCount = 0;//variable to hold pin count from microcontroller
    json microcontroller;

    vector<int> v = hardwareAmount;

    // Hardware requirements 
    int UART_REQ = v.at(0);
    int SPI_REQ = v.at(1);
    int I2C_REQ = v.at(2);
    //set initial size recommendation to a high number so the first size checked will always be picked
    int UART_REC = std::numeric_limits<int>::max();
    int SPI_REC = std::numeric_limits<int>::max();
    int I2C_REC = std::numeric_limits<int>::max();

    int tempUART = 0; //variable to hold UART support from microcontroller
    int tempSPI = 0; //variable to hold SPI support from microcontroller
    int tempI2C = 0; //variable to hold I2C support from microcontroller
   
    for(int i = 0; i < megaAvr["MegaAVRs"].size(); ++i){
      tempMem = megaAvr["MegaAVRs"][i]["Program Memory Size(KB)"];//this assignment is needed to convert to c++ int
      tempPinCount = megaAvr["MegaAVRs"][i]["Pin Count"];//this assignment is needed to convert to c++ int
      tempMem = tempMem * 1000;//convert from KB to bytes
      tempUART = megaAvr["MegaAVRs"][i]["Number of UART"];//this assignment is needed to convert to c++ int
      tempSPI = megaAvr["MegaAVRs"][i]["Number of SPI"];//this assignment is needed to convert to c++ int
      tempI2C = megaAvr["MegaAVRs"][i]["Number of I2C"];//this assignment is needed to convert to c++ int
      if((memReq < tempMem) && (pinReq < tempPinCount) && (UART_REQ <= tempUART) && (SPI_REQ <= tempSPI) && (I2C_REQ <= tempI2C)){//if program will fit in memory and pin count
         if( (tempMem <= sizeRec) && (tempPinCount <= pinCountRec) && (tempUART <= UART_REC) && (tempSPI <= UART_REC) && (tempI2C <= I2C_REC)){//if microcontroller memory size and pin count are smaller than previously selected memory size and pin count
            sizeRec = tempMem;//recommend memory size
            pinCountRec = tempPinCount;//recommend pin count
            UART_REC = tempUART;
            SPI_REC = tempSPI;
            I2C_REC = tempI2C;
            mcName = megaAvr["MegaAVRs"][i]["Name"];//recommend microcontroller
         }
      }
    }
   
    for(int i = 0; i < tinyAvr["TinyAVRs"].size(); ++i){
      tempMem = tinyAvr["TinyAVRs"][i]["Program Memory Size(KB)"];//this assignment is needed to convert to c++ int
      tempPinCount = tinyAvr["TinyAVRs"][i]["Pin Count"];//this assignment is needed to convert to c++ int
      tempMem = tempMem * 1000;//convert from KB to bytes
      tempUART = tinyAvr["TinyAVRs"][i]["Number of UART"];//this assignment is needed to convert to c++ int
      tempSPI = tinyAvr["TinyAVRs"][i]["Number of SPI"];//this assignment is needed to convert to c++ int
      tempI2C = tinyAvr["TinyAVRs"][i]["Number of I2C"];//this assignment is needed to convert to c++ int
      if( (memReq < tempMem) && (pinReq < tempPinCount) && (UART_REQ <= tempUART) && (SPI_REQ <= tempSPI) && (I2C_REQ <= tempI2C)){//if program will fit in memory and in count
         if((tempMem <= sizeRec) && (tempPinCount <= pinCountRec) && (tempUART <= UART_REC) && (tempSPI <= UART_REC) && (tempI2C <= I2C_REC)){//if memory size and pin count are smaller than previously selected memory size and pin count
            sizeRec = tempMem;//recommend memory size
            pinCountRec = tempPinCount;//recommend pin count
            UART_REC = tempUART;
            SPI_REC = tempSPI;
            I2C_REC = tempI2C;
            mcName = tinyAvr["TinyAVRs"][i]["Name"];//recommend microcontroller
         }
      }
    }
    //check if program size is close to program memory for microcontroller, if it is then bump it up to next recommendation
    //by using the previous recommending microcontroller program memory as a requirement
    if( percentChange(sizeRec, memReq) <= MEMORY_PERCENT_BUFFER ){
      mcName = recommendMicroController(sizeRec, pinReq, v);
    }//if pin count is within buffer range then bump up to next available pin count by using recommendation as requirement for new recommendation
    else if(percentChange(pinCountRec, pinReq) <= PIN_COUNT_PERCENT_BUFFER){
      mcName = recommendMicroController(memReq, pinCountRec, v);
    }
    return mcName;
}

//function to detect the libraries included in a project
vector<string> getLibraries(string fileName){
   string word;
	bool isLibrary = false;
	ifstream inFile;
   vector<string> libraries;
	//inFile.open(filePath);
	inFile.open(fileName);
	//inFile.open("D:\\IDE Workspaces\\test\\src\\test.cpp");
	//D:\IDE Workspaces\test\src\test.cpp

	if (!inFile) {//file could not be opened
	    cout << "There was an issue opening the file"<< endl;
	    exit(1);
	}

	while (inFile >> word) {
		if (isLibrary){
		word = word.substr(1, word.size() - 2);//get library name
			libraries.push_back(word);//add library to vector
			isLibrary = false;
		}
		if (word.compare("#include") == 0){
			isLibrary = true;//library found
		}
	}
	inFile.close();
   return libraries;
}

//struct to hold pin count information
struct pinCount {int digitalPins; int analogPins;};

//function to estimate pin count using libraries.json and detected libraries
pinCount getPinCount(vector<string> libraries){
   //open json files
   using json = nlohmann::json;
   std::ifstream lib("libraries.json");
   //read json objects from json files
   json libPins = json::parse(lib);
   int j;
   string tempCompare = " ";
   pinCount pins = {0,0};//instantiate pinCount struct
   for(auto const& name: libraries){//iterate through libraries found
      for(j = 0; j < libPins["Libraries"].size(); j++){//iterate through libraries.json
         tempCompare = libPins["Libraries"][j]["name"]; 
         if(name.substr(0,name.length()-2).compare(tempCompare) == 0){//if names of libraries match
            int analog = libPins["Libraries"][j]["AnalogPins"];//assignment needed to convert from json value to int
            int digital = libPins["Libraries"][j]["DigitalPins"];//assignment needed to convert from json value to int
            //add pins from library to pin count
            pins.analogPins += analog;
            pins.digitalPins += digital;
         }
      }
   }
   return pins;
}

// function that counts how much of each hardware is required based on libraries detected
vector<int> countPeripherals(vector<string> libraries){
  
   vector<int> amount;

   using json = nlohmann::json;
   std::ifstream libH("librariesHardware.json"); 
   //read json objects from json files
   json libHardware = json::parse(libH);

   int UART = 0;
   int SPI = 0;
   int I2C = 0;

   string temp = "";
   string temp2 = "";
   string final = ".h";

   for(int i = 0; i < libHardware["Libraries"].size(); ++i){
      temp = libHardware["Libraries"][i]["name"];//this assignment is needed to convert to c++ int
      temp2 = libHardware["Libraries"][i]["Requires"];
      final = temp+final;
      for(auto const& lib: libraries){
        if(lib == final){
          if(temp2 == "SPI"){
            SPI++;
          }else if(temp2 == "I2C"){
            I2C++;
          }else if(temp2 == "UART"){
            UART++;
          }
        }
      }
      final = ".h";
      
    }

   amount.push_back(UART);
   amount.push_back(SPI);
   amount.push_back(I2C);  

   return amount;
}



int main(int argc, const char ** argv) {
    
    if(argc > 1){//if a filename has been given
    string str = "";
    //get name of file to compile and measure
    str = str + argv[1];
    //compile arduino sketch using the arduino cli, capturing stdout in string output
    string output = GetStdoutFromCommand( ("arduinocli compile -b arduino:avr:uno " + str + " -o main").c_str() );
    int size = GetIntFromString(output);//get file size from arduinocli output
    vector<string> libraries = getLibraries("./example/" + str);
    pinCount pins = getPinCount(libraries);
    //indicate libraries detected
    cout << "Libraries detected: " << endl;
    for(auto const& lib: libraries){
      cout << lib << endl;
    }
    //prompt user to confirm pin count estimation
    cout << "Pin requirements estimated as " << pins.digitalPins << " digital pins and " << pins.analogPins << "analog pins." << endl;
    cout << "Is this correct(Y/N)?" << endl;
    char answer = ' ';
    cin >> answer;//get answer
    while(!cin.fail() && answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N'){//wait until prompt is answered with yes or no
      cout << "Please answer yes or no(Y/N)." << endl;//prompt for input
      cin >> answer;//get answer
    }
    if(answer == 'N' | answer == 'n'){//if estimation was wrong, prompt user for correct values
      int analog, digital;
      string input;
      char end;
      //prompt user for correct values for pin count
      bool valid = false;
      bool isInt = true;
      cin.clear();//clear cin
      cin.ignore(numeric_limits<streamsize>::max(),'\n');//clear cin
      cout << "Please enter the correct values." << endl;
      do{
         cout << "How many digital pins does your project require?" << endl;
         getline(cin, input);//get input
         int i;
         for(i = 0; i < input.length(); i++){//iterate through input string
            if(input[i] < 48 || input[i] > 57){//character that is not number or space
               isInt = false;//found not number or space character, input is invalid
               break;
            }
         }
         if(input.size() == 0){//in case user just hit enter without input
            isInt = false;
         }
         if(cin.good() && isInt){//input is valid and cin had no errors
            valid = true;
            stringstream ss(input);//create stringstream for conversion
            ss >> digital;//read int from string
         }
         else{
            cin.clear();//reset cin
            isInt = true;//reset for next input check
            cout << "Please enter an integer." << endl;
         }
      }while(!valid);//while valid input has not been entered
      
      valid = false;
      isInt = true;
      do{
         cout << "How many analog pins does your project require?" << endl;
         getline(cin, input);//get input
         int i;
         for(i = 0; i < input.length(); i++){//iterate through input
            if(input[i] < 48 || input[i] > 57){//character that is not number or space
               isInt = false;//found not number or space character, input is invalid
               break;
            }
         }
         if(input.size() == 0){//in case user just hit enter without input
            isInt = false;
         }
         if(cin.good() && isInt){//input is valid and cin had no errors
            valid = true;
            stringstream ss(input);//create stringstream for conversion
            ss >> analog;//read int from string
         }
         else{
            cin.clear();//reset cin
            isInt = true;//reset for next input check
            cout << "Please enter an integer." << endl;
         }
      }while(!valid);//while valid input has not been entered
      //set values for recommendation
      pins.analogPins = analog;
      pins.digitalPins = digital;
    }
    string microcontroller = recommendMicroController(size, pins.analogPins + pins.digitalPins, countPeripherals(libraries));//get recommended microcontroller for program size and pin count
    //output program measured, program size, pin count,and name of recommended microcontroller
    cout << "Program: " << str << endl;
    cout << "Size: " << size << " bytes" << endl;
    cout << "Analog Pins Required: " << pins.analogPins << endl;
    cout << "Digital Pins Required: " << pins.digitalPins << endl;
    cout << "Recommendation: " << microcontroller << endl;
    }
    else{
      cout << "Please enter a filename.";
    }
    return 0;
}




