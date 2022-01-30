#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int l;
    int r;
};
node A[30010];

void traverse(int s)
{
    if (s == -1) return;

    traverse(A[s].l);
    traverse(A[s].r);
    cout << s << " ";

}

int main()
{
    int N; cin >> N;
    int s, l, r;

    for (int i = 1; i <= N; i++)
    {
        cin >> s >> l >> r;
        A[s].l = l;
        A[s].r = r;
    }

    int B[30010];
    queue<int> q;
    q.push(1);

    int sum = 0;
    int num = 0;

    while(num < N)
    {
        if (q.front() == -1)
        {
            ++sum;
            q.pop();
            q.push(-1);
            q.push(-1);
            continue;
        };

        num++;
        B[q.front()] = ++sum;
        q.push(A[q.front()].l);
        q.push(A[q.front()].r);
        q.pop();
    }

    for (int i = 1; i <= N; i++)
        cout << B[i] << " ";

    cout << endl;
    traverse(1);

    return 0;
}
