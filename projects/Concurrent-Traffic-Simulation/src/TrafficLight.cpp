#include <iostream>
#include <random>
#include <chrono>
#include "TrafficLight.h"

/* Implementation of class "MessageQueue" */

/* 
template <typename T>
T MessageQueue<T>::receive()
{
    // FP.5a : The method receive should use std::unique_lock<std::mutex> and _condition.wait() 
    // to wait for and receive new messages and pull them from the queue using move semantics. 
    // The received object should then be returned by the receive function. 
}
*/

void MessageQueue::send(TrafficLightPhase &&msg)
{
    // FP.4a : The method send should use the mechanisms std::lock_guard<std::mutex> 
    // as well as _condition.notify_one() to add a new message to the queue and afterwards send a notification.

        // perform vector modification under the lock
        std::lock_guard<std::mutex> uLock(this->_mutex);

        // add vector to queue
        //std::cout << "   Message " << msg << " has been sent to the queue" << std::endl;
        _queue.push_back(std::move(msg));
        _cond.notify_one(); // notify client after pushing new Vehicle into vector
}


/* Implementation of class "TrafficLight" */
TrafficLight::TrafficLight()
{
    _currentPhase = TrafficLightPhase::red;
}
TrafficLight::~TrafficLight()
{
    _currentPhase = TrafficLightPhase::red;
}
void TrafficLight::waitForGreen()
{
    // FP.5b : add the implementation of the method waitForGreen, in which an infinite while-loop 
    // runs and repeatedly calls the receive function on the message queue. 
    // Once it receives TrafficLightPhase::green, the method returns.
}
TrafficLightPhase TrafficLight::getCurrentPhase()
{
    return _currentPhase;
}
void TrafficLight::setCurrentPhase(TrafficLightPhase phase)
{
    _currentPhase=phase;
}

void TrafficLight::simulate()
{
    // FP.2b : Finally, the private method „cycleThroughPhases“ should be started in a thread when the public method „simulate“ is called.
    //To do this, use the thread queue in the base class. 
    threads.emplace_back(std::thread(&TrafficLight::cycleThroughPhases, this));/* i make it like other classes but why this is passed?*/
}

// virtual function which is executed in a thread
void TrafficLight::cycleThroughPhases()
{
    // FP.2a : Implement the function with an infinite loop that measures the time between two loop cycles 
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    auto diff=end-start;
    while (true)
    {
        // and toggles the current phase of the traffic light between red and green  
        if(_currentPhase==TrafficLightPhase::red)
        {
            _currentPhase=TrafficLightPhase::green;
        }
        else
        {
            _currentPhase=TrafficLightPhase::red;
        }
        
        // and sends an update method to the message queue using move semantics.
        //The cycle duration should be a random value between 4 and 6 seconds. 
        TrafficLightPhaseMessageQueue.send(std::move(_currentPhase));
        
        // Also, the while-loop should use std::this_thread::sleep_for to wait 1ms between two cycles. 
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        
        
    }
}

