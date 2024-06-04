#include <iostream>
using namespace std;
//Friend function
//Friend class function
//Friend class

class User;
void Display(User &user);

class Details
{
  private:
  int DepartmentId;
  string DepartmentName;
  public:
  void SetMoreDetails(int d, const string &name)
  {
    DepartmentId = d;
    DepartmentName = name;
  }
  void MoreDetails(User &user);
};



class User
{
  private:
  int age;
  string name;
  public:
  void SetDetails(int a, const string & s)
  {
    age = a;
    name = s;
  }
  
  friend void Display(User &user);
  friend void Details::MoreDetails(User &user);
};


void Details::MoreDetails(User &user)
{
    cout << "Details :" << user.age << " " << user.name << endl;
    cout << "More details:" << DepartmentId << " " << DepartmentName << endl;
}



void Display(User &user)
{
  cout << "Details :" << user.age << " " << user.name << endl;
}


int main() 
{
    User user;
    user.SetDetails(10, "Ramesh");
    Display(user);
    
    Details details;
    details.SetMoreDetails((int)101, "IT");
    details.MoreDetails(user);
    
    
    return 0;
}
