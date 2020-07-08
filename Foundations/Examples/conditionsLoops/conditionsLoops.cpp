#include <iostream>
using std::cout;

int main() 
{
    
    /*condition evaluate boolean expression*/
    bool a=false;
    if(a)
    {
        cout<<"will not appear";
    }
    
    /*print even numbers from 1 to 10 and using while is required in the ex*/
    auto i=1;
    while(i<=10)
    {
        if(i%2==0)
            cout<<i<<" ";
        i++;
    }
    cout<<"\n";
    
    /*Note
    for should used if the number of iterations is well know*/
    for(auto i=0;i<5;i++)
    {
        cout<<i<<" ";
    }


}