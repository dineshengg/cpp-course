#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

string str = "This is a sample";
mutex mu;
condition_variable cond;

void Function1()
{
    for (int i = 0; i < 100; i++)
    {
        unique_lock<mutex> lck(mu);
        //lck.lock();
        char buffer[200] = { 0 };
        sprintf_s(buffer, 200, "%s - %d", "Thread 1", i);
        str = buffer;
        cout << "this is thread 1\n";
        //lck.unlock();
        cond.notify_all();
        
    }
}



void Function2()
{
    
    for (int i = 0; i < 100; i++)
    {
        unique_lock<mutex> lck(mu);
        //lck.lock();
        cond.wait(lck);
        cout << "this is thread 2\n";
        cout << str << "\n";
        //lck.unlock();
    }
}



int main()
{
    std::cout << "Hello World!\n";
    std::thread t1(Function1);
    std::thread t2(Function2);
    std::thread t3(Function2);
    t1.join();
    t2.join();
    t3.join();
}
