#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int l;
    int r;
    node():l(-1), r(-1){};
};
node A[1000010];

int main()
{
    int N; cin >> N;
    int tmp;
    for (int i = 1; i < N; i++)
    {
        cin >> tmp;
        if (A[tmp].l == -1) A[tmp].l = i;
        else if (A[tmp].l < i) A[tmp].r = i;
        else { A[tmp].r = A[tmp].l; A[tmp].l = i;};
    }

    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        tmp = q.front();
        if (A[tmp].l != -1) q.push(A[tmp].l);
        if (A[tmp].r != -1) q.push(A[tmp].r);
        cout << tmp << " ";
        q.pop();
    }
    return 0;
}
