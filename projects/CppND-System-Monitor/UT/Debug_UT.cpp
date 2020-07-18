#include<assert.h>
#include<string.h>
#include<iostream>
#include"../include/linux_parser.h"
#include"processor.h"
#include"process.h"
#include <unistd.h>

using namespace std;
using namespace LinuxParser;

int main()
{
  assert("Ubuntu 16.04.6 LTS"==OperatingSystem());
  cout<<"OperatingSystem"<<OperatingSystem() <<"\n";
  
  
  cout<<"Kernel"<<Kernel() <<"\n";
  cout<<"UpTime"<<UpTime()<<"\n";
  cout<<"TotalProcesses "<<TotalProcesses()<<"\n";
  cout<<"RunningProcesses "<<RunningProcesses()<<"\n";
  assert("4.15.0-1071-gcp"==Kernel());
  std::cout<<"memUtilization"<<MemoryUtilization()<<"\n" ;
  std::cout<<"processes"<<"\n";
  
  for (auto i: LinuxParser::Pids() )
  {
    
    cout<<i<<"\n";
  }
  
  std::cout<<"uid"<<LinuxParser::Uid(1)<<"\n";
  std::cout<<"user:"<<User(1)<<"\n";
  
  cout<<"processor"<<"\n";
  Processor p;
  std::cout<<p.Utilization()<<"\n";
  std::cout<<"ram:"<<Ram(1)<<"\n";
  std::cout<<"sysConfg:"<<sysconf(_SC_CLK_TCK)<<"\n";
  std::cout<<"up time process1: "<<UpTime(1)<<"\n";
  
  Process pr(1);
  std::cout<<"process cpu utilization: "<<pr.CpuUtilization()<<"\n";
  
 
  return 0;
}