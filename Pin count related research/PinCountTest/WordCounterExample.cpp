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

	ifstream fin("test.txt");
	int count = 0;
	std::string keyword = "dog";
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
