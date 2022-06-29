#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);

        int l = 1, r = n;
        while (l < r)
        {
            int m = (l + r) >> 1;

            if (l == m || r == m)
            {
                cout << "? " << l << ' ' << l << endl;
                cout.flush();

                int num;
                cin >> num;
                if (l == num)
                {
                    cout << "! " << l << endl;
                    cout.flush();
                }
                else
                {
                    cout << "! " << r << endl;
                    cout.flush();
                };

                break;
            }

            cout << "? " << l << ' ' << m << endl;
            cout.flush();

            int num, cnt = 0, cnt_tot = m - l + 1;

            for (int j = 0; j < cnt_tot; j++)
            {
                cin >> num;
                if (l <= num && num <= m)
                    cnt++;
            };

            if (cnt & 1)
                r = m;
            else
                l = m;
        };
    };
    return 0;
}