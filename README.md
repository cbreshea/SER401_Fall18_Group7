# SER401_Fall18_Group7

This is our Github for our Capstone Project. Here we will up adding code once we get our planning done. If you have any questions, feel free to email anyone of our group members.


Main code is contained in singleApplication/singleApplication.cpp

Code must be compiled with the g++ compiler option -std=gnu++11 for compatibility with the json library used.
for example: g++ -std=gnu++11 singleApplication.cpp -o singleApplication.

The program takes one input of the arduino file to analyze.
for example: singleApplication Blink.ino

The program will indicate the libraries that were detected in the project then the number of digital and analog pins required by those libraries then prompt the user to confirm if the estimation of pin requirements is correct. Finally the program will indicate the recommended microcontroller based on the arduino files memory, pin, and hardware requirements.
