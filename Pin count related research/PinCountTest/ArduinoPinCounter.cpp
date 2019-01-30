#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	string file;
	cout << "Enter the file name + extension: \n";
	cin >> file;
  ifstream myfile (file.c_str());
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
	
	
}
