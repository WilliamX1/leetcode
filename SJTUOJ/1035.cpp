#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int num;
    int x;
};

node A[20010];
int B[20010];
bool myCompare(node A, node B)
{
    if (A.x == B.x) return A.num < B.num;
    return A.x > B.x;
};
int main()
{
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &B[i]);

    int K, tmp, x, y, i, j; cin >> K;
    char ch;
    for (i = 1; i <= K; i++)
    {
        cin >> ch;

        if (ch == 'Q')
        {
            for (j = 1; j <= N; j++)
            { A[j].num = j; A[j].x = B[j];}

            sort(A + 1, A + N + 1, myCompare);
            scanf("%d", &tmp);
            for (j = 1; j <= tmp; j++)
            {
                scanf("%d", &x);
                printf("%d ", A[x].num);
            }
            printf("\n");
        }
        else
        {
            scanf("%d%d", &x, &y);
            B[x] = y;
        }
    }

    return 0;
}
