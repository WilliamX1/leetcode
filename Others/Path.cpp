#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> nums(n + 2, vector<int>(n + 2, 0));
    char ch;
    int ans = 0, tt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> ch;
            nums[i][j] = ch == 'P';
            tt += ch == 'P';
        };

    while (tt > 0)
    {
        int x, y;
        bool flag = true;

        // cout << "tt: " << tt << endl;
        // for (int i = 0; i <= n + 1; i++)
        // {
        //     for (int j = 0; j <= n + 1; j++)
        //         cout << nums[i][j] << ' ';
        //     cout << endl;
        // }
        // cout << endl;

        for (x = 1; x <= n; x++)
        {
            for (y = 1; y <= n; y++)
            {
                // cout << "ii: " << i << " jj: " << j << endl;
                if (nums[x][y])
                {
                    int tot = nums[x - 1][y] + nums[x][y - 1] + nums[x + 1][y] + nums[x][y + 1];
                    // cout << "ii: " << i << " jj: " << j << " tot: " << tot << endl;
                    if (tot <= 1)
                    {
                        flag = false;
                        break;
                    };
                };
            }
            if (!flag)
                break;
        };

        if (flag)
        {
            for (x = 1; x <= n; x++)
            {
                for (y = 1; y <= n; y++)
                    if (nums[x][y])
                    {
                        int tot = nums[x - 1][y] + nums[x][y - 1] + nums[x + 1][y] + nums[x][y + 1];
                        if (tot <= 2)
                        {
                            flag = false;
                            break;
                        };
                    };
                if (!flag)
                    break;
            };
            // cout << "flag: True i: " << i << " j: " << j << endl;
            // 矩形
            int k1, k2;
            if (nums[x - 1][y] && nums[x][y - 1])
            {
                // 左上
                for (k1 = x; k1 >= 0 && nums[k1][y]; k1--)
                    for (k2 = y; k2 >= 0 && nums[k1][k2]; k2--)
                        nums[k1][k2] = 0;
            }
            else if (nums[x][y - 1] && nums[x + 1][y])
            {
                // 左下
                for (k1 = x; k1 <= n && nums[k1][y]; k1++)
                    for (k2 = y; k2 >= 0 && nums[k1][k2]; k2--)
                        nums[k1][k2] = 0;
            }
            else if (nums[x + 1][y] && nums[x][y + 1])
            {
                // 右下
                for (k1 = x; k1 <= n && nums[k1][y]; k1++)
                    for (k2 = y; k2 <= n && nums[k1][k2]; k2++)
                        nums[k1][k2] = 0;
                // cout << "k1: " << k1 << " k2: " << k2 << endl;
            }
            else if (nums[x][y + 1] && nums[x - 1][y])
            {
                // 右上
                for (k1 = x; k1 >= 0 && nums[k1][y]; k1--)
                    for (k2 = y; k2 <= n && nums[k1][k2]; k2++)
                        nums[k1][k2] = 0;
            };
            ans += min(abs(k1 - x), abs(k2 - y));
            tt -= abs(k1 - x) * abs(k2 - y);
        }
        else
        {
            ans++;
            // cout << "flag: False i: " << i << " j: " << j << endl;
            if (nums[x - 1][y])
            {
                // 向上
                for (int k = x; k >= 0; k--)
                    if (nums[k][y] && (!nums[k][y - 1] || !nums[k][y + 1]))
                    {
                        nums[k][y] = 0;
                        tt--;
                    }
                    else
                        break;
            }
            else if (nums[x + 1][y])
            {
                // 向下
                for (int k = x; k <= n; k++)
                    if (nums[k][y] && (!nums[k][y - 1] || !nums[k][y + 1]))
                    {
                        nums[k][y] = 0;
                        tt--;
                    }
                    else
                        break;
            }
            else if (nums[x][y - 1])
            {
                // 向左
                for (int k = y; k >= 0; k--)
                    if (nums[x][k] && (!nums[x - 1][k] || !nums[x + 1][k]))
                    {
                        nums[x][k] = 0;
                        tt--;
                    }
                    else
                        break;
            }
            else if (nums[x][y + 1])
            {
                // 向右
                for (int k = y; k <= n; k++)
                {
                    if (nums[x][k] && (!nums[x - 1][k] || !nums[x + 1][k]))
                    {
                        nums[x][k] = 0;
                        tt--;
                    }
                    else
                        break;
                };
            }
            else
            {
                nums[x][y] = 0;
                tt--;
            };
        }
    }
    cout << ans << endl;

    return 0;
}