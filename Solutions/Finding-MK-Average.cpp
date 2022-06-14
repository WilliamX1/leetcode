#include <bits/stdc++.h>

using namespace std;

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */

class MKAverage
{
  public:
    vector<int> vec;
    int _m;
    int _k;
    MKAverage(int m, int k)
    {
        _m = m;
        _k = k;
    }

    void addElement(int num)
    {
        vec.push_back(num);
        return;
    }

    int calculateMKAverage()
    {
        vector<int> tmp(vec.begin() + _k, vec.end() - _k);
        /*直接排序*/
        sort(tmp.begin(), tmp.end());
        return (accumulate(tmp.begin() + _k, tmp.end() - _k, 0)) / (_m - 2 * _k);
        /*部分排序*/
        // int minus_part = 0;
        // nth_element(tmp.begin(), tmp.begin() + _k, tmp.end(), greater<int>());
        // minus_part += accumulate(tmp.begin(), tmp.begin() + _k, 0);
        // nth_element(tmp.begin(), tmp.begin() + _k, tmp.end(), less<int>());
        // minus_part += accumulate(tmp.begin(), tmp.begin() + _k, 0);
        // return (accumulate(tmp.begin(), tmp.end(), 0) - minus_part) / (_m - 2 * _k);
    }
};