#include <iostream>
#include <string>
#include <regex>
/*
This example was derived from http://www.cplusplus.com/reference/regex/regex_search/
*/
int main ()
{
  std::string s ("#include <Adafruit_NeoPixel.h> ifdef __AVR__include <avr/power.h>#endif define PIN            6");
  std::smatch m;
  std::regex e ("\\b(Adafruit_NeoPixel.h)([^ ]*)");
  while (std::regex_search (s,m,e)) {
      for (auto x:m){
          if(x != "/"){
              std::cout << x << " ";
          }else{
              continue;
          }
      }
    std::cout << std::endl;
    s = m.suffix().str();
  }

  return 0;
}
