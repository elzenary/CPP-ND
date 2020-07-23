#include <iostream>

int main()
{
    int i = 1; 
    int j = 2; 
    int k = i + j; 
    int &&l = i + j; 

    std::cout << "k = " << k << ", l = " << l << std::endl;

    return 0; 
}

/*
Since C++11, there is a new type available called rvalue reference, which can be identified from the double ampersand && after a type name. With this operator, it is possible to store and even modify an rvalue, i.e. a temporary object which would otherwise be lost quickly.

After creating the integers i and j on the stack, the sum of both is added to a third integer k. Let us examine this simple example a little more closely. In the first and second assignment, i and j are created as lvalues, while 1 and 2 are rvalues, whose value is copied into the memory location of i and j. Then, a third lvalue, k, is created. The sum i+j is created as an rvalue, which holds the result of the addition before being copied into the memory location of k. This is quite a lot of copying and holding of temporary values in memory. With an rvalue reference, this can be done more efficiently.

The expression int &&l creates an rvalue reference, to which the address of the temporary object is assigned, that holds the result of the addition. So instead of first creating the rvalue i+j , then copying it and finally deleting it, we can now hold the temporary object in memory. This is much more efficient than the first approach, even though saving a few bytes of storage in the example might not seem like much at first glance. One of the most important aspects of rvalue references is that they pave the way for move semantics, which is a mighty technique in modern C++ to optimize memory usage and processing speed. Move semantics and rvalue references make it possible to write code that transfers resources such as dynamically allocated memory from one object to another in a very efficient manner and also supports the concept of exclusive ownership, as we will shortly see when discussing smart pointers. In the next section we will take a close look at move semantics and its benefits for memory management.

*/