#include <iostream>
using namespace std;

class OldPrinter{
    public:
       void printOldPrinter()       {
        cout<<"Printing Old Printer"<<endl;
       }
};

class NewPrinter
{
  public:
    virtual void printfunction() = 0;
    virtual ~NewPrinter() = default;
};

class AdapterPrinter : public NewPrinter
{
   private:
    OldPrinter *PrinterPointer;
    public:
      AdapterPrinter(OldPrinter *Pointer):PrinterPointer(Pointer)
      {

      }
     void printfunction() override
     {
        cout<<"In AdapterPrinter"<<endl;
        PrinterPointer->printOldPrinter();
     }  

};

int main()
{
    OldPrinter *OldPrinterObj;
    NewPrinter *newprinter = new AdapterPrinter(OldPrinterObj);
    newprinter ->printfunction();
    return 0;

}