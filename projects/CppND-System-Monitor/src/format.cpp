#include <string>
#include<sstream>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {

  std::stringstream shr,smin,ssec;
  int hr=seconds/3600;
  int min=( (seconds%3600) /60);
  int sec=seconds%=60;
  
  /*adjust the format*/
  
  if(sec<10)
    ssec<<'0'<<sec;
  else    
    ssec<<sec;
  
  if(min<10)
    smin<<'0'<<min;
  else    
    smin<<min;
  
  if(hr<10)
    shr<<'0'<<hr;
  else    
    shr<<hr;

  std::string out= shr.str()+":"+smin.str()+":"+ssec.str();
  
  return out; }