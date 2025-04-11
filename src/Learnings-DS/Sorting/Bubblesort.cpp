/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

/* Bubble sorting:
Time complexity: O(n2)
Space complexity : O(n)
*/
#include <iostream>
using namespace std;
void sortarray(int arr[],int size)
{
    
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-i;j++)
        {
        if(arr[j]>arr[j+1])
        {
            int temp = arr[j];
        arr[j] = arr[j+1] ;
        arr[j+1] = temp;
        }
        }
    }
}
int main()
{
   int array[5] ={2,1,4,3,5};
   int n = sizeof(array)/sizeof(array[0]);
   sortarray(array,n);
   for(int i=0;i<n;i++)
   {
       cout<<array[i]<<"\n";
   }

    return 0;
}