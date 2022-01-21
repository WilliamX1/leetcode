#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int A;
    int B;
    int label;
};

node A[50010];

bool myFirstCompare(node A, node B){return A.A > B.A;};
bool mySecondCompare(node A, node B){return A.B > B.B;};

int main()
{
    int N, K; scanf("%d%d", &N, &K);

    for (int i = 1; i <= N; i++)
    {
        scanf("%d%d", &A[i].A, &A[i].B);
        A[i].label = i;
    }
    sort(A + 1, A + N + 1, myFirstCompare);
    sort(A + 1, A + K + 1, mySecondCompare);
    cout << A[1].label;
    return 0;
}
