#include <iostream>
#include <fstream>

using namespace std;

int searchString(fstream &, string);



int main () {


  string ledMode;
  ofstream myfile ("LED1PinExample.cpp");
  if (myfile.is_open())
  {
  	searchString(myfile, ledMode);
 // put stuff in here
    myfile.close();
    cout<< "The number of pins that are being used is: " << count << endl;
  }
  else cout << "Unable to open file";
  return 0;
}

int searchString(fstream &infile, string see)
{
    string input;
    int count=0;
    int number=0;
    while(getline(infile,input))
    {
        number++;
        cout<<"Line "<<number<<": "<<input<<endl;
        if(input.find(see,0)!=string::npos)
        {
            cout<<"found "<<see<<" in line "<<number<<endl;
            count++;
        }
    else
    {
        cout<<see<<" is not found."<<endl;
    }
    return count;

}