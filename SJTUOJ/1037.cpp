#include <iostream>
#include <algorithm>
using namespace std;

int A[10010];
int B[10010];
bool myCompare(int A, int B){return A > B;};
int main()
{
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= M; i++)
        cin >> B[i];

    sort(A + 1, A + N + 1, myCompare);
    sort(B + 1, B + M + 1, myCompare);

    int i, j;
    int sum = N;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= M && B[j] >= A[i]; j++);
        if (j <= M) {B[j] = 1e9; sum++;};
    }
    cout << sum;
    return 0;
}
