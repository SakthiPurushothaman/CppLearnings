/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
class Cricket
{
  
  public:
  virtual void display()=0;
 
};

class Board1 : public Cricket
{
    private:
    vector<string> playerName;
    public:
    void addPlayerName(string name)
    {
        playerName.push_back(name);
    }
    void display() override
    {
        for(auto& name : playerName)
        {
            cout<<name<<endl;
        }
    }
    
    
};

class Board2 : public Cricket
{
    
    private: 
    string playername;
    int score;
    public:
    Board2(string name,int value):playername(name),score(value){}
    
    void display() override
    {
        cout<<playername<< " scored " <<score<< " runs "<<endl;
    }
    
};

class DisplayBoard
{
   
    public:
      
       unique_ptr<Cricket> createBoard(int n)
       {
           if(n==1)
           {
              return make_unique<Board1>();
           }
           else if(n==2)
           {
             return make_unique<Board2>("Kohli",25);   
           }
           
           return nullptr;
       }
    
    
};
int main()
{
  DisplayBoard dispObj;
  auto ptr = dispObj.createBoard(1);
  dynamic_cast<Board1*>(ptr.get())->addPlayerName("Kohli");
  ptr->display();
  auto ptr1 = dispObj.createBoard(2);
  ptr1->display();
}