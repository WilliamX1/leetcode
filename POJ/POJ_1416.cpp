#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int have[20];
int tar, num;
int len, MAX;
int pieces[100000], p_xb;
int true_pieces[100000], t_xb;

bool Dfs(int pos, int sum)
{
    if (sum > tar) return false;
    if (pos == len) { MAX = max(MAX, sum); return true;}

    bool flag = false;
    for (int i = pos + 1; i <= len; i++)
    {
        int tmp = 0;
        for (int j = pos + 1; j <= i; j++) tmp += have[j] * pow(10.0, double(j - pos - 1));
        if (Dfs(i, sum + tmp))
            { pieces[++p_xb] = tmp; flag = true;};
    }
    return flag;
}
int main()
{
    cin >> tar >> num;
    int i, j, k, tmp;

    while(tar != 0 || num != 0)
    {
        bool F = true;
        if (tar == num) cout << num << " " << num << endl;
        else if (tar >= num) cout << "error\n";
        else
        {
            int true_max = -1;
            for (i = 1; num > 0; i++)  //处理数据
            { have[i] = num % 10; num /= 10;};
            len = i - 1;

            for (i = 1; i < len && F; i++)
            {
                p_xb = 0;
                tmp = MAX = 0;
                for (j = 1; j <= i; j++)
                    tmp += have[j] * pow(10.0, double(j - 1));
                if (Dfs(i, tmp))
                {
                    if (true_max == MAX) { cout << "rejected" << endl; F = false; break;}
                    else if (MAX > true_max)
                    {
                        pieces[++p_xb] = tmp;
                        t_xb = p_xb;
                        for (j = 1; j <= t_xb; j++)
                            true_pieces[j] = pieces[j];
                        true_max = MAX;
                    }
                }
            }
            if (F)
            {
                if (true_max == -1) cout << "error" << endl;
                else
                {
                    cout << true_max << " ";
                    for (j = 1; j <= t_xb; j++) cout << true_pieces[j] << " ";
                    cout << endl;
                    int x[10]; int x_xb = 0; int x_sum = 0;
                    for (j = t_xb; x_sum != len; j--)
                    {
                        x[++x_xb] = true_pieces[j];
                        for (k = 1; true_pieces[j] > 0; k++)
                            true_pieces[j] /= 10;
                        x_sum += k - 1;
                    }
                    for (i = x_xb; i >= 1; i--)
                        cout << x[i] << " ";
                    cout << endl;
                }
            }
        }
    cin >> tar >> num;
    }
    return 0;
}
