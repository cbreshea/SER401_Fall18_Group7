#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	string file;
	string keyword = "dog";
	string word;
	int count = 0;
	//cout << keyword;
	cout << "Enter the file name + extension: \n";
	cin >> file;
  ifstream myfile (file.c_str());
  while(myfile >> word){
		//cout << word << " ";
		if(word == keyword){
			count++;
		}
	}
	cout << count;
  /*
  if (myfile.is_open())
  {
    while ( getline (myfile,file) )
    {
      cout << file << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
	*/
	
}
