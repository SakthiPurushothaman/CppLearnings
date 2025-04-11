#include <iostream>
#include <math.h>
using namespace std;

void swap(int &a , int &b)
 {
//     int temp = a;
//     a = b;
//     b = temp;

a =a^b;
b=a^b;
a=a^b;

}
bool isPrime(int no)
{
    if (no == 1 || no == 2)
    {
        return true;
    }

    for (auto i = 2; i < sqrt(no); i++)
    {
        if (no % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool CheckPrime(int array[], int size)
{
    bool value;
    for (int i = 0; i < size; i++)
    {
        value = isPrime(array[i]);
        if (value == false)
        {
            return false;
        }
    }
    return true;
}

int fibonacciSeries(int no)
{
    if (no == 0)
    {
        return 0;
    }
    if (no == 1)
    {
        return 1;
    }

    return fibonacciSeries(no-1) + fibonacciSeries(no - 2);
}

int factorial(int no)
{
    if (no == 0 | no == 1)
    {
        return 1;
    }

    return no * factorial(no - 1);
}

int reverseNumber(int no)
{
    int result = 0;
    int digit = no % 10;
    result = result * 10 + digit;
    return result;
}

bool IsperfectSquare(int no)
{
    int sqNum;
    if (no == 0)
        return false;
    sqNum = static_cast<int>(sqrt(no));
    if (no == (sqNum * sqNum))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num = 25;
    // bool res = CheckPrime(arr,size);
    // if(res)
    // {
    //     cout<<"All numbers in the array are prime."<<endl;
    // }
    // else
    // {
    //     cout<<"All numbers in the array are not prime."<<endl;
    // }
    //    for (int i = 0; i < num; ++i) {
    //     cout << fibonacciSeries(i) << " ";
    // }

    //  int n = factorial(num);
    // int n = reverseNumber(nu
  //  bool res = IsperfectSquare(num);

   // cout << res << endl;
   int a =10; int b =11;
   swap(a,b);
   cout<<"After swappting"<<" "<<a<<endl<<b<<endl;
    return 0;
}