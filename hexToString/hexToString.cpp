#include <sstream>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


/*Program that converts hex values to string
Will be used to look for pincount within hex file*/
void convertToString(std::string hexVal);
void convertToBinary(std::string hexVal);

int main(int argc, const char ** argv) {


    /*const char *filename = "hello.txt";
    ifstream read_file(filename, fstream::in);

    std::string val;
    read_file >> convertToString(filename) >> val; // read hex value
    cout << val << "\n"; // display hex value*/

    ifstream find("hello.txt");

    string name;

    while (find >> name)
    {
        //convertToString(name);
    }
	
	convertToString(name);
    
    std::string hexVal = "48656c6c6f";
	convertToString(hexVal);
	return 0;
}


void convertToString(std::string hex){
	int size = hex.length();
	std::string word;
	char * pEnd;
	for(int i=0; i< size; i+=2)
	{
		//grab each byte
	    string two = hex.substr(i,2);
	    char single = (char) (int)strtol(two.c_str(), &pEnd, 16);
	    //shift to convert to string
	    word.push_back(single);
	}
	cout << word << "\n";
}

void convertToBinary(std:: string hex){
	hex = "0xA";
    stringstream str;
    str << hex << str;
    unsigned num;
    str >> num;
    bitset<32> b(num);
    cout << b.to_string() << endl;
}