#include <iostream>
using namespace std;

//Shallow copying
//Deep copying

class Resource
{
  private:
  int size;
  int *data;
  public:
  Resource():size(0), data(nullptr)
  {
    
  }
  
  Resource(int a)
  {
    size = a;
    data = new int[10];
    for(int i=0; i< size; i++)
    {
      data[i] = i;
      // *(data+i) = i;
    }
  }
  
  Resource(const Resource& obj)
  {
    size = obj.size;
    data = new int[size];
    for(int i=0; i<size; i++)
    {
      data[i] = obj.data[i];
    }
  }
  
  void Update()
  {
    data[2] = 10;
  }
  
  void Display()
  {
    for(int i=0; i <size; i++)
    {
      cout<<data[i]<< " ";
    }
  }
};

int main() 
{
    int *ptr = new int[10];
    Resource a(10);
    Resource b = a;
    a.Display();
    b.Update();
    a.Display();
    b.Display();
    //b.Update();
    delete [] ptr;
    
    return 0;
}
