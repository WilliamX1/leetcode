#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int W;  //权值
    int D;  //渴望度
};
node A[3500];
int B[15200];
bool myCompare(node A, node B){return A.W < B.W;};

int main()
{
    int N, M; cin >> N >> M;
    int i, j;

    for (i = 1; i <= N; i++)
        cin >> A[i].W >> A[i].D;
    sort(A + 1, A + N + 1, myCompare);
    for (i = 1; i <= 15000; i++) B[i] = 0;

    for (int i = 1; i <= N; i++)
    {
        int x = A[i].W;
        if (B[x] != 0 && x < 7000) B[2 * x] = max(B[2 * x], B[x] + A[i].D);
        if (B[x] > A[i].D) continue;
        B[x] = A[i].D;
        for (int j = 1; j <= x - 1 && x + j < 13000; j++)
            B[x + j] = max(B[x + j], B[x] + B[j]);
    }
    cout << *max_element(B + 1, B + M + 1);
    return 0;
}
