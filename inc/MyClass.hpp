#include <cstring>
#include <algorithm>
using namespace std;

class Myclass
{
    private:
    int* data;
    int size;

    public:
    Myclass(int s): size(s)
    {
        data = new int[size];
    } 

    Myclass(const Myclass &other) :size(other.size),data(new int[other.size])
    {
          std::memcpy(data,other.data,size*sizeof(int));
    }
    Myclass& operator = (const Myclass &other)
    {
        if(this != &other)
        {
            delete[] data;
        
        size = other.size;
        data = new int[other.size];
         std::copy(other.data,other.data+size,data);
        memcpy(data,other.data,size*sizeof(data));
        }
        return *this;
    }
    

    Myclass(Myclass && other) noexcept:size(other.size),data(other.data){

        other.size = 0;
        other.data = nullptr;
    }

    Myclass &operator=(Myclass && other)
    {
        if(this != &other)
        {
            delete[] data;
        
                  size = other.size;
            data = other.data;

            other.data = nullptr;
            other.size = 0;
        }

        return * this;
    }

       ~Myclass()
    {
        delete[] data;
    }
};

int main()
{
    Myclass obj1(5);
    Myclass obj2 = obj1;
    Myclass obj3(10);
    obj2 =obj3;
    Myclass obj4 = std::move(obj1);
    Myclass obj5(5);
    obj5 = std::move(obj3);


     
;}