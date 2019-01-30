#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	
	
	string keyword = "dog";
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
	cout << count;
	
	return 0;

}
