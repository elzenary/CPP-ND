#include <iostream>
#include <thread>

class Vehicle
{
public:
    void operator()()
    {
        std::cout << "Vehicle object has been created \n" << std::endl;
    }
};


int main()
{
    // create thread 
    /*this can be considered function decleration instead of anonymos object ambiguity*/
    //std::thread t(Vehicle()); // C++'s most vexing parse
    
    /*possible solution from my side*/
    Vehicle v;
    std::thread t(v); // C++'s most vexing parse
    /*another possible soultion in the next example*/

    // do something in main()
    std::cout << "Finished work in main \n";

    // wait for thread to finish
    t.join();

    return 0;
}