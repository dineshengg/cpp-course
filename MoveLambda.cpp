#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//lambda expressions
//rvalue reference 
//move semantics and move constructor

void PrintVector(vector<int> vec)
{
  for_each(vec.begin(), vec.end(), [](int &a)
  {
    cout<< a << " ";
  });
}

class A 
{
  private:
  int data;
  int *ptr;
  public:
  A(int d1, int d2)
  {
    data = d1;
    ptr = new int(d2);
  }
  
  A(const A& obj)
  {
    cout << "copy constructor\n";
    data = obj.data;
    ptr = new int();
    *ptr = *obj.ptr;
  }
  
  A(A&& obj)
  {
    cout << "move constructor\n";
    data = obj.data;
    ptr = obj.ptr;
    obj.data = 0;
    obj.ptr = nullptr;
  }
  
  ~A()
  {
    if(ptr != nullptr)
      delete ptr;
  }
  
  void Display()
  {
    cout << data << "\n";
  }
  
  A& operator = (A&& obj)
  {
    if(this != &obj)
    {
      data = obj.data;
      ptr = obj.ptr;
      
      obj.ptr = nullptr;
      obj.data = 0;
    }
    return *this;
  }
};

void Function(A b)
{
  b.Display();
}

A Function1()
{
  A obj(10, 2);
  return obj;
}


template<typename T>
void Function2(T&& arg) // universal reference 
{
  cout << "std forward example \n";
  Function3(std::forward<T>(arg));
}

void Function3(A obj)
{
  obj.Display();
}

int main() 
{
    cout << "Hello, World!";
    auto square = [] (int a)->int{ return a*a; };
    
    vector<int> vec = {1,2,3,4,5,6,10,22,12};
    sort(vec.begin(), vec.end(), [](int &a, int &b)->int{ return a < b;});
    cout << "sorting \n";
    
    PrintVector(vec);
    cout << square(2);
    
    cout << "\n";
    //r-value reference
    int i = 10; // i is l-value, 10 is a r-value
    int a = 2;
    int *ptr = &a; //ptr is a l-value and a is also a l-value
    int &b = a;// b is a l-value reference
    int &&bb = 10; //10 is a r-value and bb is a r-value reference
    
    //Move constructor
    A obj1(10, 20);
    A obj2 = std::move(obj1); // copy constructor
    
    Function(Function1());//copy constructor
    //std::move()
    obj1.Display();
    
    cout << "move constructor \n";
    Function2(std::move(obj2));
    
    obj1 = std::move(obj2); //move assignment operator
    
    return 0;
}
