#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>
using namespace std;

//int M[2][1000010];
//int m[2][1000010];

vector<int> v;
int M[1000010];
int m[1000010];

int main()
{
    int n, k; scanf("%d%d", &n, &k);

    int d;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d);
        v.push_back(d);
    }
    deque<int> qmax;
    deque<int> qmin;

    for (int i = 0; i < n; i++)
    {
        while(!qmax.empty() && v[i] > v[qmax.back()])
            qmax.pop_back();
        if (!qmax.empty() && i - qmax.front() >= k)
            qmax.pop_front();
        qmax.push_back(i);

        while(!qmin.empty() && v[i] < v[qmin.back()])
            qmin.pop_back();
        if (!qmin.empty() && i - qmin.front() >= k)
            qmin.pop_front();
        qmin.push_back(i);

        M[i] = v[qmax.front()];
        m[i] = v[qmin.front()];
    }

    for (int i = k - 1; i < n; i++)
        printf("%d ", m[i]);
    printf("\n");
    for (int i = k - 1; i < n; i++)
        printf("%d ", M[i]);
    return 0;
}


/*int main()
{
    int n, k; cin >> n >> k;

    for (int j = 1; j <= n; j++)
    {
        scanf("%d", &M[0][j]);
        m[0][j] = M[0][j];
    }

    for (int i = 2; i <= k; i++)
    {
        for (int j = 1; j <= n + 1 - i; j++)
        {
            M[1][j] = max(M[0][j], M[0][j + 1]);
            m[1][j] = min(m[0][j], m[0][j + 1]);
        }
        for (int j = 1; j <= n + 1 - i; j++)
        {
            M[0][j] = M[1][j];
            m[0][j] = m[1][j];
        }
    }

    for (int j = 1; j <= n + 1 - k; j++)
        printf("%d ", m[0][j]);
    printf("\n");
    for (int j = 1; j <= n + 1 - k; j++)
        printf("%d ", M[0][j]);

    return 0;
}*/
