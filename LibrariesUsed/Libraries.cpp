//============================================================================
// Author      : Jared LeBlanc
// Description : Outputs the libraries that a given program is using
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	string word;
	bool isLibrary = false;
	string filePath;
	ifstream inFile;

	for (int i = 0; i < argc; ++i){
	        filePath.append(argv[i]);
	        if (i < argc -1)
	        	filePath.append(" ");
	}

	cout << filePath;
	//inFile.open(filePath);
	inFile.open("D:\\IDE Workspaces\\test\\src\\test.cpp");
	//inFile.open("D:\\IDE Workspaces\\test\\src\\test.cpp");
	//D:\IDE Workspaces\test\src\test.cpp

	if (!inFile) {
	    cout << "There was an issue opening the file";
	    exit(1);
	}

	while (inFile >> word) {
		if (isLibrary){
		word = word.substr(1, word.size() - 2);
			cout << word << '\n';
			isLibrary = false;
		}
		if (word.compare("#include") == 0){
			isLibrary = true;
		}
	}
	inFile.close();
	return 0;
}