#include <numeric>
#include <vector>
#include <deque>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long res = 0;
        const int mod = 1000000000 + 7;
        /*复刻arr数组*/
        deque<int> array;
        for (int i = 0; i < arr.size(); i++)
            array.push_back(arr[i]);
        int len = array.size();

        while (len > 0) {
            res += accumulate(begin(array), end(array), 0.0);
            while (--len) {
                array.push_back(min(array[0], array[1]));
                array.pop_front();
            }
            array.pop_front();

            len = array.size();
        };
        return res % mod;
    }
};

int main()
{
    Solution S;
    vector<int> v = {11,81,94,43,3};
    printf("%d", S.sumSubarrayMins(v));
    return 0;
}