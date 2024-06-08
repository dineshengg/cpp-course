#include <iostream>
#include <list>
#include <map>
using namespace std;
//STL managing the data in list 
//Namespace

namespace Developer1
{
  void FunctionToWriteAFile()
  {
    cout << "Writting some content - Developer1\n";
  }
}

namespace Developer2
{
  void FunctionToWriteAFile()
  {
    cout << "Writting some content - Developer2\n";
  }
}


class Employee
{
  private:
  unsigned int age;
  string name;
  unsigned long Empid;
  public:
  Employee():age(0), name(""),Empid(0)
  {
    
  }
  
  Employee(const Employee &emp)
  {
    age = emp.age;
    name = emp.name;
    Empid = emp.Empid;
  }
  
  Employee(unsigned int a, const string &n, unsigned long id)
  {
    age = a;
    name = n;
    Empid = id;
  }
  void Display()
  {
    cout << "Employee name, age and id is :" << name << " " << age << " "<< Empid << "\n";
  }
};

int main() 
{
    cout << "Hello, World!\n";
    list<Employee > lst; //time 0(N)
    lst.push_back(Employee(25, "Ramesh", 1001));
    lst.push_back(Employee(26, "Suresh", 1002));
    lst.push_back(Employee(24, "Ganesh", 1003));
    
    int size = lst.size();
    for(auto i = 0; i < size; i++)
    {
      Employee emp = lst.front();
      emp.Display();
      lst.pop_front();
    }
    
    //Employee id with details
    map<int, Employee> mp;
    mp[1001] = Employee(25, "Ramesh", 1001);
    mp[1003] = Employee(24, "Ganesh", 1003);
    
    for(auto it =mp.begin(); it != mp.end(); it++)
    {
      cout << "Key :" <<it->first << " " << "Employee details ";
      it->second.Display();
    }
    
    Employee emp = mp[1003]; //O(log N)
    emp.Display();
    
    Developer1::FunctionToWriteAFile();
    
    
    return 0;
}
