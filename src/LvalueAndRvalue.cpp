


// C++ program to illustrate rvalue
#include <iostream>
using namespace std;
 
// Declaring rvalue reference to the
// rvalue passed as the parameter
void printReferenceValue( int&& x)
{
   
    cout << x <<" "<<"Inside rvalue ref"<< endl;
}

void printReferenceValue( int& x)
{

    cout << x<<" "<<"Inside lvalue ref"<<endl;
}
 
template <typename T>
void forwarder(T &&arg)  // will work for forwarder(10)
{
    printReferenceValue(std::forward<T>(arg));
}
// Driver Code
int main()
{
    // Given value a
    int a{ 10 };
    forwarder(a);  // calls lvalue 
    forwarder(100);  // calls rvalue 
  //   // printReferenceValue(a);

    //    printReferenceValue(100);
    return 0;
}