#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
int L[100010];  //³¤
int H[100010];  //¿í

int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &L[i], &H[i]);

    int cur = max(L[1], H[1]);
    for (int i = 2; i <= n; i++)
    {
        if (max(L[i], H[i]) <= cur)
            cur = max(L[i], H[i]);
        else if (min(L[i], H[i]) <= cur)
            cur = min(L[i], H[i]);
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
