
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
#include <iostream>
 
class Cents
{
private:
    int m_cents;
 
public:
    Cents(int cents) { m_cents = cents; }
 
    int getCents() const { return m_cents; }
};
 
void print(const Cents &cents)
{
   std::cout << cents.getCents() << " cents";
}
 
int main()
{
    print(Cents(6)); // Note: Now we're passing an anonymous Cents value
 
    return 0;
}