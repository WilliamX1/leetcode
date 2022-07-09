#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    vector<int> nums(4);
    while (t--)
    {
        for (int i = 0; i < 4; i++)
            cin >> nums[i];
        int tt = accumulate(nums.begin(), nums.end(), 0);
        if (tt == 0)
            cout << 0 << endl;
        else if (tt == 4)
            cout << 2 << endl;
        else
            cout << 1 << endl;
    };
    return 0;
}