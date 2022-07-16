#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int64_t N, a, b;
    cin >> N >> a >> b;

    vector<int64_t> nums(N);
    for (int64_t i = 0; i < N; i++)
        cin >> nums[i];

    int64_t left = 0, right = 1e9 + 7;
    while (left <= right)
    {
        int64_t mid = (left + right) >> 1;

        int64_t atot = 0, btot = 0;
        for (int64_t i = 0; i < N; i++)
        {
            if (nums[i] > mid)
                btot += (nums[i] - mid) / b;
            else if (nums[i] < mid)
                atot += (mid - nums[i] - 1) / a + 1;
        };
        if (btot >= atot)
            left = mid + 1;
        else
            right = mid - 1;
    };
    cout << right << endl;
    return 0;
}