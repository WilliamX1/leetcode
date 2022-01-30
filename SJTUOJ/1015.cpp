#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int main()
{
    string a, b; cin >> a >> b;
    int lenA = a.length(), lenB = b.length();
    int A[1024], B[1024];
    for (int i = 0; i < lenA; i++) A[i] = a[lenA - i - 1] - '0';
    for (int i = 0; i < lenB; i++) B[i] = b[lenB - i - 1] - '0';

    int res[1024];
    memset(res, 0, sizeof(res));

    for (int i = 0; i < lenA; i++)
        for (int j = 0; j < lenB; j++)
            res[i + j] += A[i] * B[j];

    int yushu = 0;
    for (int i = 0; i < lenA + lenB; i++)
    {
        res[i] += yushu;
        yushu = res[i] / 10;
        res[i] %= 10;
    }
    int cur = lenA + lenB;
    while(cur > 0 && !res[cur]) cur--;

    for (int i = cur; i >= 0; i--)
        printf("%d", res[i]);

    return 0;
}
