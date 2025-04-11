#include <iostream>
#include <memory>
using namespace std;
int main()
{
   unique_ptr<int> uni_ptr = make_unique<int>(10);
   shared_ptr<int> sha_ptr = make_shared<int>(10);
   cout<<"count1"<<sha_ptr.use_count()<<endl;
   shared_ptr<int> sha_ptr1 = sha_ptr;
   cout<<"count2"<<sha_ptr1.use_count()<<endl;
   sha_ptr.reset();
   cout<<"count3"<<sha_ptr1.use_count()<<endl;

   weak_ptr<int> wp = sha_ptr1;
   if(auto sha_ptr1 = wp.lock())
   {
     cout<<"Resource working"<<endl;
   }
    return 0;
}