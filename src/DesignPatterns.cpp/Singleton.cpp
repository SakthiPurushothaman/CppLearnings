/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

class Singleton
{
private:

	Singleton() {
		std::cout << "Singleton Created\n";
	}
public:
	Singleton(const Singleton&) = delete;
	Singleton& operator = (const Singleton&)  = delete;

	static Singleton& getInstance()
	{
		static Singleton instance;
		return instance;
	}

	void showMessage() {
		std::cout << "Singleton instance address: " << this << std::endl;
	}

};

int main()
{
	Singleton& obj = Singleton::getInstance();
    obj.showMessage();
    	Singleton& obj1 = Singleton::getInstance();
    obj.showMessage();

	return 0;
}