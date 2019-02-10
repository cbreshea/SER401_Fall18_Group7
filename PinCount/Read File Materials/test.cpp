// C++ implementation to read file
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    // filestream variable file 
    fstream file; 
    string word, t, q, filename; 
  
    // filename of the file 
    filename = "sample.cpp"; 
  
    // opening file 
    file.open(filename.c_str()); 
  
    // extracting words form the file 
    while (file >> word) 
    { 
        // displaying content 
        cout << word << endl; 
    } 
  
    return 0; 
} 