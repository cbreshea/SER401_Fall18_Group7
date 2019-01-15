//============================================================================
// Name        : PinCount.cpp
// Author      : Jared LeBlanc
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
using namespace std;

int main() {
	int n;
	ifstream inFile;
	inFile.open("C:\\Users\\Jared\\Desktop\\UseMe\\test.txt");

	if (!inFile) {
	    cout << "There was an issue opening the file";
	    exit(1);
	}

	while (inFile >> n) {
	  cout << "yo!";
	  inFile.close();
	}
	return 0;
}
