#include <iostream>

void myFunction(int &val)
{
    std::cout << "val = " << val << std::endl;
}

int main()
{
    int j = 42;
    myFunction(j);

    myFunction(42);

    int k = 23; 
    myFunction(j+k);

    return 0; 
}

/*

Rvalue references
You already know that an rvalue is a temporary expression which is - among other use-cases, a means of initializing objects. In the call int i = 42, 42 is the rvalue.

Let us consider an example similar to the last one, shown on the right.

As before, the function myFunction takes an lvalue reference as its argument. In main, the call myFunction(j) works just fine while myFunction(42) as well as myFunction(j+k) produces the following compiler error on Mac:

candidate function not viable: expects an l-value for 1st argument

and the following error in the workspace with g++:

error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’

While the number 42 is obviously an rvalue, with j+k things might not be so obvious, as j and k are variables and thus lvalues. To compute the result of the addition, the compiler has to create a temporary object to place it in - and this object is an rvalue.

*/