#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <mutex>
#include <deque>
#include <condition_variable>
#include "TrafficObject.h"

// where TrafficLightPhase is an enum that can be either „red“ or „green“
enum class TrafficLightPhase {red , green};

// forward declarations to avoid include cycle
class Vehicle;


// FP.3 Define a class „MessageQueue“ which has the public methods send and receive. 
// Send should take an rvalue reference of type TrafficLightPhase whereas receive should return this type. 
// Also, the class should define an std::dequeue called _queue, which stores objects of type TrafficLightPhase. 
// Also, there should be an std::condition_variable as well as an std::mutex as private members. 

class MessageQueue
{
public:
    TrafficLightPhase receive();
    void send(TrafficLightPhase &&msg);

private:
    std::mutex _mutex;
    std::condition_variable _cond;
    std::deque<TrafficLightPhase> _queue;
};

// FP.1 : Define a class „TrafficLight“ which is a child class of TrafficObject. 
class TrafficLight: public TrafficObject
{
public:
    // constructor / desctructor
    TrafficLight();
    ~TrafficLight();

    // getters / setters
    void setCurrentPhase(TrafficLightPhase phase);
    // as well as „TrafficLightPhase getCurrentPhase()“, 
    TrafficLightPhase getCurrentPhase();
    
    // typical behaviour methods
    
    // The class shall have the public methods „void waitForGreen()“ and „void simulate()“ 
    void waitForGreen();
    void simulate();

private:
    // Also, add the private method „void cycleThroughPhases()“. 
    void cycleThroughPhases();

    // Furthermore, there shall be the private member _currentPhase which can take „red“ or „green“ as its value. 
    TrafficLightPhase _currentPhase;

    // FP.4b : create a private member of type MessageQueue for messages of type TrafficLightPhase 
    // and use it within the infinite loop to push each new TrafficLightPhase into it by calling 
    // send in conjunction with move semantics.
    MessageQueue TrafficLightPhaseMessageQueue;
    std::condition_variable _condition;
    std::mutex _mutex;
};


#endif