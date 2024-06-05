#include <iostream>
using namespace std;

//Friend class
class B;

class A 
{
  private:
  int details;
  
  public:
  
  A()
  {
    
  }
  
  A(int data)
  {
    details = data;
  }
  
  void FunctionA()
  {
    cout<<"A::FunctionA\n";
    cout<<details << "\n";
  }
  friend class B;
};

class B 
{
  private:
  int b;
  A obj;
  
  public:
  
  B(A &a)
  {
    obj = a;
  }
  
  void FunctionB()
  {
    cout << "B::FunctionB\n";
    cout << "A data " << obj.details <<"\n";
  }
  
  void FunctionB1()
  {
    obj.details = 100;
  }
};


class User
{
  private:
  int age;
  string name;
  public:
  User(int a, string b)
  {
    age = a;
    name = b;
  }
  public:
  friend ostream& operator << (ostream &o, User &obj);
};

ostream& operator << (ostream &o, User &obj)
{
  o<<"Age and name "<<obj.age << "  " << obj.name;
  return o;
}

int main() 
{
    A obj(10);
    obj.FunctionA();
    
    B obj1(obj);
    obj1.FunctionB();
    obj1.FunctionB1();
    obj1.FunctionB();
    
    obj.FunctionA();
    
    User user(10, "Ramesh");
    User user1(20, "Suresh");
    cout << user << user1;
    
    return 0;
}
