
#include<iostream>  
  
using namespace std;
int main(){
	

ifstream file("PinMode.txt");    
int wcount = 0;
string token;
string word("PIN_MODE");
while (file>>token)
    if (word == token)
    wcount++;

cout << "The number of pins that this program uses is" << wcount << endl;
}