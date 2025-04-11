#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class PrintOddEvenNumbers
{
	int no;
	mutex mtx;
	condition_variable cv_odd;
	condition_variable cv_even;
	bool isOdd = true;

public:
	PrintOddEvenNumbers(int n):no(n) {}
	void printOddNumber()
	{

		for(int i =1; i<=no; i+=2)
		{
			unique_lock<mutex> lock(mtx);
			cv_odd.wait(lock,[this]() {
				return isOdd;
			});
			cout<<i<<endl;
			isOdd = false;
			cv_even.notify_one();

		}

	}
	void printEvenNumber()
	{

		for(int i =2; i<=no; i+=2)
		{
			unique_lock<mutex> lock(mtx);
			cv_even.wait(lock,[this]() {
				return !isOdd;
			});
			cout<<i<<endl;
			isOdd = true;
			cv_odd.notify_one();

		}

	}

};

int main()
{
	PrintOddEvenNumbers print(20);
	thread t1(&PrintOddEvenNumbers::printOddNumber,&print);
	thread t2(&PrintOddEvenNumbers::printEvenNumber,&print);
	t1.join();
	t2.join();
	return 0;
}
