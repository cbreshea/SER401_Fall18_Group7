#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	

	ifstream fin;
	int count = 0;
	std::string keyword = "dog";
	std::string found;

	
    fin.open("dog.txt");
    while (fin >> found){
	   if (found[0] == '/'){
	   	  continue;
	   }else if(found.starts_with('/*')){
	   		if (found.starts_with('*/')){
                   if (line.starts_with('*/')){
	   				continue;
	   			   }	
             }
	   }else{
	   	  cout << found << "\n";
	   	  count++;
	   }
    }

    /*while(fin){
		fin >> found;
		if(found[0] == "/"){
			continue;
		}else if(found == keyword){
			count++;
		}
	}*/


	cout << "Occurence="<<count<<"\n";
	fin.close();

	
	return 0;

}