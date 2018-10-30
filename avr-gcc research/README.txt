How to modify compiler options

1. find your installation of arduino
2. navigate to ./hardware/arduino/avr
3. open platform.txt
4. add flags to compiler.c.flags or compiler.cpp.flags lines 

How to get assembly code of arduino project

this method works on windows and i am unsure if steps are different for mac

1. find destination folder for compiled files
	shift click verify in arduino IDE
	or
	go to File>Preferences and check Show verbose output during compilation
	look near end of output for filepath to files, likely to be under AppData\Local\Temp in a folder like arduino_build_#####
2. use command prompt to run avr-objdump -S fileName.elf and this should output the assembly code to your command prompt