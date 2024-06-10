#include <iostream>
#include <memory>
using namespace std;
//unique_ptr
//shared_ptr
//weak_ptr
//smart pointer to manage the memory in heap
class Dog
{
  private:
  string Name;
  int age;
  string breed;
  public:
  Dog(const string&n)
  {
    Name =n;
  }
  void Bark()
  {
    cout << "I am a Dog " << Name;
  }
  ~Dog()
  {
    cout << Name << "is destroyed";
  }
};

void Function(unique_ptr<Dog> obj)
{
  obj->Bark();
}

void Function1(shared_ptr<Dog> obj) //2
{
  obj->Bark();
}

int main() 
{
    cout << "Hello, World!";
    {
    //ownership of an object
    unique_ptr<Dog> ptr(new Dog("Jimmy"));
    unique_ptr<Dog> ptr2;
   // ptr2 = std::move(ptr);
    
    Function(std::move(ptr));
    
    Dog *ptr1 = ptr.get();
    if(ptr == nullptr)
    {
      cout << "ptr is empty\n";
    }
    }
    
    //shared ownership with reference counting
    shared_ptr<Dog> ptr = make_shared<Dog>("Jimmy"); // 1
    ptr->Bark();
    
    shared_ptr<Dog> ptr1 = ptr; //2
    ptr1->Bark();
    cout << ptr1.use_count() << endl;
    ptr1.reset(); //1
    cout << ptr1.use_count() << endl;
    ptr->Bark();
    Function1(ptr); //1
    
    //weak pointer used for avoiding cyclic reference
    weak_ptr<Dog> obj1 = ptr; //1
    weak_ptr<Dog> obj2 = ptr; //1
    if(!obj1.expired())
    {
      obj1.lock()->Bark(); //2
    }
    return 0;
}
