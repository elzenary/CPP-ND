
/*include required headers*/
#include<iostream>
#include<vector>
#include<numeric>

/*use right name spaces*/
using std::cout;/* cout is object of class ostream. It is used to display the output to the standard output device i.e. monitor*/
using std::vector;/*Vectors are sequence containers representing arrays that can change in size and it is part of STL library*/

/*Define 2D vector*/

/*initializeation can be by different ways*/
auto x{3};
auto y=3;
auto v={ 1,2,3 };                        

/*add using for over range and pass by refrence to save coppying*/
int AdditionFunctionForRanged(const vector<int>& v)
{
    int sum=0;
    for(const int& i : v)
    {
        sum+=i;
    }
    
    return sum;
}

/*make the sum throght iterators*/
int AdditionFunctionIterators(const vector<int>& v)
{
    int sum = 0;
    for (auto i = v.begin(); i < v.end(); i++)
    {
        sum += *i;
    }

    return sum;
}

int AdditionFunctionaccumulate(const vector<int>& v)
{
    return std::accumulate(v.begin(), v.end(), 0);
}

int AdditionFunctionaIndexing(const vector<int>& v)
{
    int sum =0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return sum;
}


int main()
{
    
    cout<<x<<" "<<y<<"\n";

    cout << "sum="<< AdditionFunctionaccumulate(v)<<","<< AdditionFunctionIterators(v) <<","
        << AdditionFunctionForRanged(v)<<","<< AdditionFunctionaIndexing(v)<<"\n";

    return 0;
}