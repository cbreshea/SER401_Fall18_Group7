#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    //String for the file's words
	string file;
    //Keyword we are going to use to compare
	string keyword = "ledPin";
    //Sring of the current file's word
	string word;
    //int for the number of times the keyword was found
	int count = 0;
    
	cout << "Enter the file name + extension: \n";
    //Read in the file and start comparing word for word
	cin >> file;
  ifstream myfile (file.c_str());
  while(myfile >> word){
		if(word == keyword){
			count++;
		}
	}
	cout << "The amount of pins in this project is: ";
	cout << count;
}
