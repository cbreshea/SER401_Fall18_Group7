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
	
	string = "";

	foreach(string word in file)
    {
    char[] character = word.ToCharArray();
	    foreach(char i in character)
	    {
	        if (i == '/' || i == '')
	        {
	            break;
	        }
	        else 
	        {
	        	string = "";
	        }
	    }
	}   

	while(file >> word){
		//cout << word << " ";
		if (word == '/'){
			continue;
		}

		if(word.find("/")){
			continue;
		}

		if(word == keyword){
			count++;
		}
	}
	cout << count;
	
	return 0;

}
