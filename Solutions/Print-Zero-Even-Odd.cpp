#include <iostream>
#include <condition_variable>
#include <mutex>

using namespace std;

class ZeroEvenOdd {
private:
    int n;
    int cnt = 1;
    bool flag = true;
    mutex mtx;
    condition_variable cv_zero;
    condition_variable cv_odd;
    condition_variable cv_even;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (cnt <= n) {
            std::unique_lock<mutex> lock(mtx);
            if (flag) {
                cout << 0;
                flag = false;
            }
            if (cnt % 2 == 0) cv_even.notify_one();
            else cv_odd.notify_one();
            cv_zero.wait(lock);
        };
    }

    void even(function<void(int)> printNumber) {
        while (cnt <= n) {
            std::unique_lock<mutex> lock(mtx);
            if (!flag) {
                cout << cnt++;
                flag = true;
            };
            cv_zero.notify_one();
            cv_even.wait(lock);
        }
    }

    void odd(function<void(int)> printNumber) {
        while (cnt <= n) {
            std::unique_lock<mutex> lock(mtx);
            if (!flag) {
                cout << cnt++;
                flag = true;
            };
            cv_zero.notify_one();
            cv_odd.wait(lock);
        }
    }
};