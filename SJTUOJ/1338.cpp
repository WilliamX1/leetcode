#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int Start;
    int End;
};

node A[100010];

bool myCompare(node A, node B){return A.End < B.End;};

int main()
{

    int N; cin >> N;

    for (int i = 1; i <= N; i++)
        scanf("%d%d", &A[i].Start, &A[i].End);
    A[0].Start = A[0].End = 0;

    sort(A + 1, A + N + 1, myCompare);

    int sum = 0;

    int i = 0, last;
    while(i <= N)
    {
        last = i;
        i++;
        while(i <= N && A[i].Start < A[last].End) i++;
        if (i <= N) sum++;
    }
    cout << sum;
    return 0;
}
