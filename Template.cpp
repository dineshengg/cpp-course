#include <iostream>
using namespace std;
//Template
//Function template
template<typename t1>
t1 Calculate(t1 i, t1 j)
{
  return i+j;
}

template<typename A, typename B>
class user1
{
  private:
  A t1;
  B t2;
  public:
  void Display()
  {
    cout << t1 << t2;
  }
};

class Details
{
  private:
  int depcode;
  int empid;
  public:
  Details()
  {
  
  }
  
  Details(int d, int emp)
  {
    depcode = d;
    empid = emp;
  }
  
  void Display()
  {
    cout << "Dep code" << depcode << " " << empid << endl;
  }
};

template<typename A>
class User
{
  private:
  int age;
  string name;
  A details;
  public:
  User(int a, const string &n, const Details &d)
  {
    this->age = a;
    this->name = n;
    this->details = d;
  }
  
  User(const User&obj)
  {
    this->age = obj.age;
  }
  
  User& operator = (const User &obj)
  {
    if(this != &obj)
    {
      age = obj.age;
      name = obj.name;
      details = obj.details;
    }
    return *this;
  }

  void Display()
  {
    cout << "User " << age << " " << name << endl;
    details.Display();
  }
  
  void SetDetails(Details &d)
  {
    details = d;
  }
  
};


int main() 
{
    cout << Calculate<float>(10.1,20.2) << endl;
    user1<int, string> obj;
    
    Details d1(100, 10001);
    Details d2(100, 10002);
    User<Details> user(10, "Ramesh", d1);
    User<Details> user1(25, "Tarun", d2);
    user.Display();
    user1.Display();
    user = user1;
    //user.SetDetails(d1);
    //user1.SetDetails(d2);
    
    return 0;
}
