#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	
	
	/*string keyword = "dog";
	string word;
	//cout << keyword;
	
	int count = 0;
	fstream file("test.txt");
	
	while(file >> word){
		//cout << word << " ";
		if(word == keyword){
			count++;
		}
	}
	cout << count;*/

	ifstream fin("FastLEDRainbow.ino.standard.hex");
	int count = 0;
	std::string keyword = ":00000001FF";
	std::string found;

	while(fin){
		fin >> found;
		if(found == keyword){
			count++;
		}
	}

	cout << "Occurence="<<count<<"\n";
	fin.close();

	
	return 0;

}
