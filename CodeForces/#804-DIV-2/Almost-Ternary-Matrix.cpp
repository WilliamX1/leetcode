#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> nums(2, vector<int>(m));
        nums[0][0] = 1;

        // 第一行
        int cur = 0;
        for (int j = 1; j < m - 1; j += 2)
        {
            nums[0][j] = nums[0][j + 1] = cur;
            cur = !cur;
        };
        nums[0][m - 1] = cur;
        // 第二行
        nums[1][0] = nums[0][1];
        nums[1][m - 1] = nums[0][m - 2];
        for (int j = 1; j < m - 1; j++)
            if (nums[0][j - 1] ^ nums[0][j + 1])
                nums[1][j] = !nums[0][j];
            else
                nums[1][j] = nums[0][j];

        int base = 0;
        for (int i = 0; i < n; i += 2)
        {
            for (int j = 0; j < m; j++)
                cout << nums[base][j] << ' ';
            cout << endl;
            for (int j = 0; j < m; j++)
                cout << nums[!base][j] << ' ';
            cout << endl;
            base = !base;
        };
    };
    return 0;
}