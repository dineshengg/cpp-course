#include <iostream>
using namespace std;
//operator overloading
class Data
{
  private:
  int data;
public:
  Data(int a)
  {
    data = a;
  }
  
  Data()
  {
    
  }
  
  Data(const Data &d)
  {
    
  }
  
  int operator + (const Data &obj)
  {
    return this->data + obj.data;
  }
  
  int operator - (const Data &obj)
  {
    return this->data - obj.data;
  }
  
  int operator * (const Data &obj)
  {
    return this->data * obj.data;
  }
  
  float operator / (const Data &obj)
  {
    return (float)this->data/obj.data;
  }
  
  // !=
  //<
  //>=
  //<=
  bool operator == (const Data &obj)
  {
    if(this->data == obj.data)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

class Calculator
{
  private:
     Data d;
  public:
  int Add(Data &d1, Data &d2)
  {
    return d1+d2;
  }
  
};

int main() 
{
    Data d1((int)2);
    Data d2((int)2);
    
    bool status = d1 == d2;
    cout << status << endl;
    
    Calculator cal;
    cout << cal.Add(d1, d2);
    
    return 0;
}
