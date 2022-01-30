#include <bits/stdc++.h>
#include <stdio.h>
#include <queue>

using namespace std;
int A[100010];
int B[100010];
int res[100010];

int main()
{
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &B[i]);
    for (int i = 1; i <= N; i++)
        scanf("%d", &A[i]);
    sort(A + 1, A + N + 1);
    sort(B + 1, B + N + 1);

    priority_queue< int, vector<int>, less<int> > q;

    for (int i = 1; i <= N; i++)
        q.push(A[1] + B[i]);
    for (int i = 2; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            if (A[i] + B[j] >= q.top())
                continue;
            q.pop();
            q.push(A[i] + B[j]);
        }


    for (int i = 1; i <= N; i++)
    {
        res[N - i + 1] = q.top();
        q.pop();
    }
    for (int i = 1; i <= N; i++)
        printf("%d ", res[i]);

    return 0;
}
