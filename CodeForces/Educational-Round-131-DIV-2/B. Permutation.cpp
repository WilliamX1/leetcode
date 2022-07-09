#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<bool> nums(n + 1, true);

        cout << 2 << endl;
        for (int start = 1; start <= n; start++)
            if (nums[start])
            {
                cout << start << ' ';
                nums[start] = false;

                int right = start * 2;
                while (right <= n)
                {
                    cout << right << ' ';
                    nums[right] = false;
                    right <<= 1;
                };
            };

        cout << endl;
    };
    return 0;
}