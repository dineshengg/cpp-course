#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

//sort(vec.begin(), vec.end());
//copy(first, last, result);
//move(first, last, result);
//swap(x, y);
//merge(first1, last1, first2,  last2, result);
//replace(first, last, old_value, new_value);
//transform(arr, arr+n, arr, increment);
//Functors
//transform(arr, arr+n, arr, increment(to_add));

int Increment(int value)
{
  return value+10;
}

class Increment
{
  private:
  int increment;
  public:
  Increment(int a)
  {
    increment = a;
  }
  
  int operator() (int value)
  {
    return increment + value;
  }
};

int main() 
{
    cout << "Hello, World!";
   // istream_iterator<int> cin_i(cin);
   // istream_iterator<int> eos;
    
   // ostream_iterator<int> cout_i(cout, " ");
   // copy(cin_i, eos, cout_i);
    
   // cout <<endl;
    vector<int> vec = {10,3,1,44,22,1};
    std::sort(vec.begin(), vec.end(), less<int>());
    
    for(auto it = vec.begin(); it != vec.end(); it++)
    {
      cout << *it << " ";
    }
    cout << "Sorting done \n";
    
    vector<int> res(6);
    std::copy(vec.begin(), vec.begin()+4, res.begin());
    for(auto it = res.begin(); it != res.end(); it++)
    {
      cout << *it << " ";
    }
    cout <<"Copy done\n";
    
    std::move(vec.begin(), vec.end(), res.begin());
    for(auto it = res.begin(); it != res.end(); it++)
    {
      cout << *it << " ";
    }
    
    vector<int> vec1 = {1,2,3,4,5,6};
    std::swap(vec, vec1);
    for(auto it = vec1.begin(); it != vec1.end(); it++)
    {
      cout << *it << " ";
    }
    
    cout<<"\n";
    
    vector<int> vec2(4);
    std::merge(vec.begin(), vec.begin()+2, vec1.begin()+2, vec1.begin()+4, vec2.begin());
    for(auto it = vec2.begin(); it != vec2.end(); it++)
    {
      cout << *it << " ";
    }
    
   
    cout << "\n";
    vector<int> res1(6);
    class Increment obj(2);
    std::transform(vec.begin(), vec.end(), res1.begin(), obj);
    for(auto it = res1.begin(); it != res1.end(); it++)
    {
      cout << *it << " ";
    }
    
    return 0;
}
