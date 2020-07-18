#include <string>
#include <vector>
#include "linux_parser.h"
#include "processor.h"
#include"iostream"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  
/*souce https://stackoverflow.com/questions/23367857/accurate-calculation-of-cpu-usage-given-in-percentage-in-linux*/
  float CPU_Percentage=(float)LinuxParser::ActiveJiffies()/LinuxParser::Jiffies();
  return CPU_Percentage; 
}