#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <mutex>
typedef unsigned long long ull;
ull oddSum = 0;
ull evenSum = 0;

using namespace std;

void OddSumFn(int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        if ((i & 1) == 0)
        {
            oddSum += i;
        }
    }
}
void EvenSumFn(int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        if ((i & 1) == 1)
        {
            evenSum += i;
        }
    }
}
class Base
{
    public:
    void operator () (int x)
    {
        while(x -- > 0)
        {
            cout<<x<<endl;
        }
    }

};

class BaseClass{
    

public:
  void printfunction(int x)
  {
    while(x-->0)
    {
        cout<<x<<" "<<endl;
    }
  }
 static void printfunction1(int x)
  {
    while(x-->0)
    {
        cout<<x<<" "<<endl;
    }
  }

};


int value=5;
mutex mtx;
void modifyValue()
{   
    mtx.lock();
    unique_lock<mutex> lck(mtx);
    value++;
   
    mtx.unlock();

}

int main()
{

    // ull a = 0;
    // ull b = 10000000;
    // auto startTime = std::chrono::high_resolution_clock::now();
    // // OddSumFn(a, b);
    // // EvenSumFn(a, b);
    // // Function pointer(callable methods)
    // thread t1(OddSumFn, a, b);
    // thread t2(EvenSumFn, a, b);
    // t1.join();
    // t2.join();
    // // Using lambda funtion
    // // thread t3([](int x)
    // // {
    // //     while(x-- > 0)
    // //     {
    // //         cout<<x<<endl;
    // //     }
    // // },10
    // // );
    // // t3.join();
    // // Uisng funcotrs
    // /* In C++, a functor (short for function object) is any object that can be called like a function using the function call operator ().*/
    // thread t4((Base()),10);
    // t4.join();
    // // Using non static function of a class
    // BaseClass baseobj;
    //  thread t5(&BaseClass::printfunction,&baseobj,10);
    // // Static member function
    // thread t6(BaseClass::printfunction1,10);

    // auto stopTime = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime);
    // cout << duration.count() << endl;
    int  no =10;
    auto add = [no](int a, int b) { std::cout << "Sum: " << a + b + x << std::endl; };
    std::thread th(std::move(add), 3, 4);
    thread th1(modifyValue);
    thread th2(modifyValue);
    th1.join();
    th2.join();
     cout<<"value:"<<value<<endl;
    return 0;
}
