#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool A[1024];

struct node
{
    int l;
    int r;
    node():l(0),r(0){};
};
node B[1024];
int main()
{
    int N; cin >> N;
    int x, y, z;

    memset(A, 0, sizeof(A));
    while(cin >> x >> y >> z)
    {
        B[x].l = y;
        B[x].r = z;
        A[y] = A[z] = 1;
    }

    int root;
    for (int i = 1; i <= N; i++)
        if (A[i] == 0) { root = i; break;};

    queue<int> q;
    q.push(root);

    while(!q.empty())
    {
        cout << q.front() << endl;
        if (B[q.front()].l) q.push(B[q.front()].l);
        if (B[q.front()].r) q.push(B[q.front()].r);
        q.pop();
    }

    return 0;
}
