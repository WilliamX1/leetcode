#include <iostream>
#include <algorithm>
using namespace std;
struct sweet
{
    int value;
    int weight;
    double average;
};
sweet A[120];

bool myCompare(sweet A, sweet B){return A.average > B.average;};
int main()
{
    int N, W; cin >> N >> W;

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i].value >> A[i].weight;
        A[i].average = double(A[i].value) / double(A[i].weight);
    }
    sort(A + 1, A + N + 1, myCompare);

    int total_w = 0;
    double total_v = 0;

    for (int i = 1; i <= N; i++)
    {
        if (A[i].weight + total_w > W)
        {
            total_v += (W - total_w) * A[i].average;
            break;
        }
        total_w += A[i].weight;
        total_v += A[i].value;
    }
    printf("%.1f", total_v);
    return 0;
}
