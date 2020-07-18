#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>
#include<iostream>
#include <unistd.h>
#include "linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;


// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, ver, kernel;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >>ver>> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() {  
  string line;
  string key;
  string value="";
  /*array contains MemTotal, MemFree, MemAvailable, Buffers ordered by index*/
  long memValues[4];
  std::ifstream filestream(kProcDirectory+kMeminfoFilename);
  if (filestream.is_open()) {
    for(int i=0;i<4;i++)
    {
      std::getline(filestream, line);
      std::istringstream linestream(line);
      linestream >> key >> memValues[i]>>value;
      }

  }
  /*
  utilization Percentage=(memTotal-memFree)/memTotal
  */
   
  return ( (float) ( (float)memValues[0]-memValues[1] ) /memValues[0] ); }

// TODO: Read and return the system uptime
long LinuxParser::UpTime() { 
  
  long upTime;
  string line;
  std::ifstream stream(kProcDirectory + kUptimeFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> upTime;
  }
  
  return upTime; }

// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies()
{ 
  return ActiveJiffies()+IdleJiffies();
}

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid) {

   std::vector<std::string> cpuData(22);
  string line;
  long ActiveJiffiesLoc;
  std::ifstream stream(kProcDirectory +to_string(pid)+ kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
     for(int i=0;i<22;i++)
     	linestream >>cpuData[i];
    /*
     #14 utime
     #15 stime 
     #16 cutime 
	 #17 cstime 
     and -1 because the base is 0 inside cpuData
     */
     ActiveJiffiesLoc=std::stol(cpuData[13])+std::stol(cpuData[14])+std::stol(cpuData[15])+std::stol(cpuData[16]);
     //std::cout<<"\n"<<"activeJiffers: "<<ActiveJiffiesLoc<<"\n";
     return ActiveJiffiesLoc;
  }
  
  return 0;
}

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() {
  std::vector<long> vec=LinuxParser::CpuUtilization();
  long ActiveJiffesLoc=vec[LinuxParser::kUser_] + vec[LinuxParser::kNice_] + vec[LinuxParser::kSystem_]  + vec[LinuxParser::kIRQ_] + vec[LinuxParser::kSoftIRQ_] + vec[LinuxParser::kSteal_];
  return ActiveJiffesLoc;
}

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() {
  std::vector<long> vec=LinuxParser::CpuUtilization();
  long IdleJiffiesLoc=vec[LinuxParser::kIdle_]+vec[LinuxParser::kIOwait_];
  return IdleJiffiesLoc; 
}

// TODO: Read and return CPU utilization
vector<long> LinuxParser::CpuUtilization() {
  std::string cpuTemp;
  string line;
  std::vector<long> cpuData(10);
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
     linestream >>cpuTemp;
    for(int i=0;i<10;i++)
    linestream >>cpuData[i] ;
  }
  return cpuData;
}


// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() {
  
  string line;
  string key;
  int value;
  std::ifstream filestream(kProcDirectory+kStatFilename);
  //std::cout<<"before";
  if (filestream.is_open()) 
  {
    //std::cout<<"file open";
    while (std::getline(filestream, line))
    {
      //std::cout<<line<<"\n";
      key=line.substr(0,9);
      //std::cout<<key<<"\n";
      if (key == "processes")
      {
         std::istringstream linestream(line);
          linestream >> key >> value ;
          return value;
        }
     }
  }
  
  return 0;
}

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() { 
  
    string line;
  string key;
  int value;
  std::ifstream filestream(kProcDirectory+kStatFilename);
  //std::cout<<"before";
  if (filestream.is_open()) 
  {
    //std::cout<<"file open";
    while (std::getline(filestream, line))
    {
      //std::cout<<line<<"\n";
      key=line.substr(0,13);
      //std::cout<<key<<"\n";
      if (key == "procs_running")
      {
         std::istringstream linestream(line);
          linestream >> key >> value ;
          return value;
        }
     }
  }
  
  return 0;
}

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid) { 
  string line;
  std::ifstream stream(kProcDirectory + to_string(pid) +kCmdlineFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
  }
  return line;

}

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid) {
  
      string line;
  string key;
  int value;
  std::ifstream filestream(kProcDirectory+to_string(pid)+kStatusFilename);
  if (filestream.is_open()) 
  {
    while (std::getline(filestream, line))
    {
      key=line.substr(0,7);
      if (key == "VmSize:")
      {
         std::istringstream linestream(line);
         linestream >> key >> value ;
         value*=0.001;    
         return to_string(value);
        }
     }
  }
  
  
  return string(); }

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid) {
  
  string line;
  string key;
  int value=-1;
  std::ifstream filestream(kProcDirectory+to_string(pid)+kStatusFilename);
  //std::cout<<"before";
  if (filestream.is_open()) 
  {
    while (std::getline(filestream, line))
    {
      //std::cout<<line<<"\n";
      key=line.substr(0,4);
      if (key == "Uid:")
      {
         std::istringstream linestream(line);
          linestream >> key >> value ;
          return to_string(value);
        }
     }
  }
  
  return string(); }

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid) { 
  string line;
  string key;
  string uidLoc=LinuxParser::Uid(pid);
  std::ifstream filestream(kPasswordPath);
  if (filestream.is_open()) 
  {
    while (std::getline(filestream, line))
    {
      std::stringstream linestream(line);
      std::string seg;
	  std::vector<std::string> segVec;
	  while(std::getline(linestream, seg, ':'))
      {
   		segVec.push_back(seg);
      }
      
      if(segVec[2]==uidLoc)
      		return segVec[0];
      
      segVec.clear();

     }
  }
  return string(); }

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid) {
  std::string cpuTemp;
  string line;
  long upTimeLoc;
  std::ifstream stream(kProcDirectory +to_string(pid)+ kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
     for(int i=0;i<22;i++)
     	linestream >>cpuTemp;
   
     upTimeLoc=std::stol(cpuTemp);
     upTimeLoc/=sysconf(_SC_CLK_TCK);
     return upTimeLoc;
  }
  
  return 0;
}