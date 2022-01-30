#include <iostream>
#include <stack>
using namespace std;

const int inf = 1e9;

int A[12][2];

int B[12][12];

int main()
{
    int N; scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &B[i][j]);

    for (int i = 1; i <= N; i++)
    {
        A[i][1] = B[1][i];  //代表距离
        A[i][0] = 1; //代表编号
    }

    for (int i = 1; i <= N; i++)
        for (int j = i - 1; j > 1; j--)
        {
            if (B[i][j] + A[j][1] < A[i][1])
            {
                A[i][1] = B[i][j] + A[j][1];
                A[i][0] = j; //改变上一路编号
            }
        }

    printf("%d\n", A[N][1]);

    stack<int> s;

    int i = N;
    while(i != 1)
    {
        s.push(i);
        i = A[i][0];
    }

    printf("%d ", 1);
    while(!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }


    return 0;
}
