/*************************************************************
    date: Spring 2022
    copyright: Bintao Yu
    DO NOT distribute this code without my permission.
**************************************************************/
/********* Begin **********/
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *p = new int[n];
    int *flag = new int[10 + 1];
    memset(flag, 0, sizeof(flag));
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        flag[p[i]]++;
    };

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            for (int k = 1; k <= 10; k++)
            {
                if (flag[i])
                {
                    flag[i]--;
                    if (flag[j])
                    {
                        flag[j]--;
                        if (flag[k])
                        {
                            flag[k]--;
                            if ((i + j + k) % 10 == 0)
                            {
                                int ans = 0;
                                for (int s = 0; s < n; s++)
                                    ans += p[s];
                                ans %= 10;
                                cout << (ans == 0 ? 10 : ans) << endl;
                                return 0;
                            };
                            flag[k]++;
                        };
                        flag[j]++;
                    };
                    flag[i]++;
                };
            };

    cout << 0 << endl;
    return 0;
}

/********** End **********/
// You can use class.cpp and class.h if you want to.