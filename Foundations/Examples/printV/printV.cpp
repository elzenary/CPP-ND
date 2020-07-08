
/*include required headers*/
#include<iostream>
#include<vector>

/*use right name spaces*/
/*
namespace is designed to overcome this difficulty and is used as additional information to differentiate similar functions, classes, variables etc. with the same name available in different libraries.
Using namespace, you can define the context in which names are defined. In essence, a namespace defines a scope.
*/
//using namespace std;
using std::cout;/* cout is object of class ostream. It is used to display the output to the standard output device i.e. monitor*/
using std::vector;/*Vectors are sequence containers representing arrays that can change in size and it is part of STL library*/

/*Define 1D vector*/
/*
placeholder type specifiers (since C++11)
For variables, specifies that the type of the variable that is being declared will be automatically deduced from its initializer.
For functions, specifies that the return type will be deduced from its return statements. (since C++14)
For non-type template parameters, specifies that the type will be deduced from the argument. (since C++17)
*/
auto v={7,8,9,10};/*vector Definition(initialization*)/

/*define main function (entry point)*/
int main()
{
    
    /*print the vector by looping over the container*/
    /*Range-based for loop (since C++11)*/
    for(auto i : v)
    {
        cout<<i<<" ";/*operator over loading is used here baased on the class definition*/
    }
    
    /*returning zero means that the program is excuted without errors*/
    return 0;
}