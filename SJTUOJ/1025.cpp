#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int x1;
    int x2;
};
node A[20010];
bool myCompare(node A, node B){return A.x1 < B.x1;};

int main()
{
    int N; cin >> N;

    for (int i = 0; i < N; i++)
        scanf("%d%d", &A[i].x1, &A[i].x2);

    sort(A, A + N, myCompare);
    int l = A[0].x1, r = A[0].x2;
    int sum = 0;
    for (int i = 1; i < N; i++)
        if (A[i].x1 <= r)
        {
            if (A[i].x2 > r)
                r = A[i].x2;
        }
        else
        {
            sum += r - l;
            l = A[i].x1;
            r = A[i].x2;
        }
    cout << sum + r - l;
    return 0;
}
