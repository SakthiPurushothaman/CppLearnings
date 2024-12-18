#include<iostream>
#include<../inc/Operations.hpp>

using namespace std;

void addOperation(int a , int b)
{
    int c = a+b;
    if(c%2==0)
{
    cout<<"The result is even";
}
else
{
    cout<<"The result is odd";
}
     
}
