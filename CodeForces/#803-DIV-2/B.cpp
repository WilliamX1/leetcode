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
        int n, k;
        scanf("%d%d", &n, &k);

        vector<int> v(n);
        for (int j = 0; j < n; j++)
            scanf("%d", &v[j]);

        if (k == 1)
            printf("%d\n", (n - 1) / 2);
        else
        {
            int tt = 0;
            for (int j = 1; j < n - 1; j++)
                if (v[j] > v[j - 1] + v[j + 1])
                    tt++;
            printf("%d\n", tt);
        };
    };
    return 0;
}