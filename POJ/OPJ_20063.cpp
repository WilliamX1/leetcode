#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int A[1010];
struct node
{
    int weight;
    int money;
    double average;
};

bool myCompare(node A, node B){return A.average > B.average;};

int main()
{
    memset(A, 0, sizeof(A));

    int N, C; cin >> N >> C;

    node* B = new node[N];

    for (int i = 0; i < N; i++) scanf("%d", &B[i].weight);
    for (int i = 0; i < N; i++) scanf("%d", &B[i].money);
    for (int i = 0; i < N; i++) B[i].average = double(B[i].money) / B[i].weight;

    sort(B, B + N, myCompare);

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        int b = C / B[i].weight;
        sum += b * B[i].money;
        C -= b * B[i].weight;
    }

    printf("%d", sum);
    return 0;
}
