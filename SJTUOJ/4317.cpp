#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int x;
    int xb;
};
node A[100010];

bool myCompare(node A, node B)
{
    if (A.x == B.x) return A.xb < B.xb;
    return A.x < B.x;
}
int main()
{
    int N, m; cin >> N;

    for (int i = 0; i < N; i++)
    {
        A[i].xb = i;
        cin >> A[i].x;
    }

    sort(A, A + N, myCompare);

    cin >> m;
    int cha, x = 0, y = 0, i, j;
    int MAX = 0;

    for (i = 0; i < N; i++)
    {
        cha = m - A[i].x;
        for (j = N - 1; j > i; j--)
        {
            if (A[j].x == cha)
            {
                if (A[j].x - A[i].x > MAX)
                {
                    x = A[i].xb;
                    y = A[j].xb;
                    MAX = A[j].x - A[i].x;
                }
                break;
            }
        }

    }
    cout << x << " " << y;
    return 0;
}
