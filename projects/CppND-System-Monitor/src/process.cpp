#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>
#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int Pid_var)
{
    this->Pid_var=Pid_var;
}
// TODO: Return this process's ID
int Process::Pid() { return  this->Pid_var; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization(){
  
    /*source https://stackoverflow.com/questions/16726779/how-do-i-get-the-total-cpu-usage-of-an-application-from-proc-pid-stat/16736599#16736599*/

  long total_time=LinuxParser::ActiveJiffies( this->Pid()) ;
  total_time/=sysconf(_SC_CLK_TCK);
  long seconds=LinuxParser::UpTime()-LinuxParser::UpTime(this->Pid());
  float CPU_usage=(float)total_time/seconds;
  return CPU_usage; 
}

// TODO: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(this->Pid()); }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(this->Pid()); }

// TODO: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User( this->Pid() ); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(this->Pid()); }
