How to modify compiler options
------------------------------

1. find your installation of arduino
2. navigate to ./hardware/arduino/avr
3. open platform.txt
4. add flags to compiler.c.flags and compiler.cpp.flags lines 

You may have to edit the files r/w permissions or security settings to allow for editing of the file.

compiler optimization flags are:
	-Os size optimization, default for arduino, uses O2 optimizations not expected to increase code size
	-O0 no optimization
	-O1 moderate optimization, tries for speed and size without great impact to compile time
	-O2 balanced optimization
	-O3 speed optimization, may result in very large files due to inlining functions

if multiple flags are specified the last in sequence will be used

How to get assembly code of arduino project
-------------------------------------------

this method works on windows and i am unsure if steps are different for mac

1. find destination folder for compiled files
	shift click verify in arduino IDE
	or
	go to File>Preferences and check Show verbose output during compilation
	look near end of output for filepath to files, likely to be under AppData\Local\Temp in a folder like arduino_build_#####
2. use command prompt to run avr-objdump -d fileName.elf and this should output the assembly code to your command prompt
	alternatively use -S instead of -d to get output with source code mixed into the assembly, this is nice because it can make it
	a little easier to see what assembly code matches what part of the source code
	files may be too large to be displayed in command line, add "> (filepath optional)filename.extension" after the command
	to output the result to a file