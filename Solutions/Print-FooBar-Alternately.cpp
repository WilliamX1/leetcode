#include <iostream>
#include <vector>
#include <thread>
#include <condition_variable>

using namespace std;

class FooBar {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    bool flag = true;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this](){return flag == true;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            flag = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this](){return flag == false;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            flag = true;
            cv.notify_one();
        }
    }
};