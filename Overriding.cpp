#include <iostream>
using namespace std;

//Function overriding

class Base
{
  private:
  int a;
  public: 
  void FunctionA()
  {
    cout << "Base::FunctionBaseA\n";
  }
  
  virtual void FunctionB()
  {
    cout << "Base::FunctionBaseB\n";
  }
  
  virtual void Search()
  {
    cout<<"Base::Search\n";
  }
};

class Derived: public Base
{
  private:
  int b;
  public:
  void FunctionA()
  {
    cout << "Derived::FunctionDerivedA\n";
  }
  
  void FunctionB() override
  {
    cout << "Derived::FunctionDerivedB\n";
  }
  
  void Search() override
  {
    cout<<"Derived::Search\n";
  }
};


void ClientCode(Base *ptr)
{
  //business logic
  ptr->FunctionA();
  ptr->FunctionB();
  ptr->Search();
}

int main() 
{
    Derived b;
    Base *ptr = &b;
    ptr->FunctionA();//compile time binding
    ptr->FunctionB();//run time binding or dynamic polymorphism
    Base *ptr1 = new Derived();
    ClientCode(ptr1);
    delete ptr1;
    //b.FunctionA();
    //b.FunctionB();
    //Base *ptr = new Base();
    //ClientCode(ptr);
    return 0;
}
