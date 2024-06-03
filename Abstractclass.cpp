#include <iostream>
using namespace std;

//Abstract class

class File
{
  private:
  string FileName;
  public:
  File(const string & f)
  {
    FileName = f;
  }
  virtual bool ReadFile() = 0;
  virtual bool WriteFile() = 0;
  void CommonFunction()
  {
    cout<<"Implemented code\n" << FileName;
  }
};

class WebAPI
{
public:
  virtual void GetUserData() = 0;
  virtual void SetUserData() = 0;
  virtual void UpdateUserData() = 0;
  virtual void DeleteUserData() = 0;
};

class DataBaseFUnction
{
  public:
  virtual void ConnectDB() = 0;
  virtual void RunQuery(string & query) = 0;
};

class SuperSystem: public WebAPI
{
public:
  void GetUserData()
  {
    
  }
  
  void SetUserData()
  {
    
  }
  
  void UpdateUserData()
  {
    
  }
  
  void DeleteUserData()
  {
    
  }
};

class System: public WebAPI, public DataBaseFUnction
{
  private:
  int data;
  public:
  
  void GetUserData()
  {
    cout << "GetUserData\n";
  }
  
  void SetUserData()
  {
    
  }
  
  void UpdateUserData()
  {
    
  }
  
  void DeleteUserData()
  {
    
  }
  
  void ConnectDB()
  {
    cout<< "ConnectDB\n";
  }
  
  void RunQuery(string & query)
  {
    
  }
};

class FileImplementor : public File
{
  public:
  FileImplementor(const string &s):File(s)
  {
    
  }
  bool ReadFile() override
  {
    cout << "Read file\n";
    return true;
  }
  
  bool WriteFile() override
  {
    cout << "WriteFile\n";
    return true;
  }
  
};

int main() 
{
    WebAPI *ptr1 = new SuperSystem();
    ptr1->GetUserData();
    
    DataBaseFUnction *ptr2 = new System();
    ptr2->ConnectDB();
    
    FileImplementor stream("C:\\test.txt");
    stream.ReadFile();
    stream.CommonFunction();
    return 0;
}
