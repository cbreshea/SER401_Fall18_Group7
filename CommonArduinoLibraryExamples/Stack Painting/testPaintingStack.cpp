#include <iostream> 
#include <stack> 
using namespace std; 

void showstack(stack <int> s) 
{ 
	while (!s.empty()) 
	{ 
		cout << '\t' << s.top(); 
		s.pop(); 
	} 
	cout << '\n'; 
} 

int main () 
{ 
	stack <int> s; 
	s.push(10); 
	s.push(30); 
	s.push(50);

	cout << "This is a rough cpp example of what stack painting is" << endl;
	cout << "Here we are pushing the following: 10, 30 , 50 in that order to the stack" <<  endl;
	cout << "The stack is : "; 
	showstack(s); 


	cout << "bottom of stack in Arduino is " << s.top(); 


	return 0; 
} 
